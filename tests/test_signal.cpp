#include <doctest/doctest.h>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include "signal_io.hpp"
#include "random.hpp"

TEST_CASE("generateSaw daje znane wartosci") {
    std::vector<uint8_t> s = generateSaw(8, 4);
    std::vector<uint8_t> expected = (std::vector<uint8_t>{0, 64, 128, 192, 0, 64, 128, 192});
    CHECK(s == expected);
}

TEST_CASE("generateNoise z tym samym seedem jest powtarzalny") {
    auto rng1 = makeRng(42, RngStream::Signal);
    auto rng2 = makeRng(42, RngStream::Signal);
    CHECK(generateNoise(500, rng1) == generateNoise(500, rng2));
}

static std::string tmpFile(const std::string& name, const std::string& content) {
    auto path = (std::filesystem::temp_directory_path() / name).string();
    std::ofstream(path) << content;
    return path;
}

TEST_CASE("CSV: zapis i odczyt daje to samo") {
    auto rng = makeRng(42, RngStream::Signal);
    std::vector<uint8_t> s = generateNoise(1000, rng);
    s.push_back(0);
    s.push_back(255);

    auto path = (std::filesystem::temp_directory_path() / "uep_roundtrip.csv").string();
    saveCsv(path, s);
    CHECK(loadCsv(path) == s);
}

TEST_CASE("CSV: pusty sygnal") {
    auto path = (std::filesystem::temp_directory_path() / "uep_empty.csv").string();
    saveCsv(path, {});
    CHECK(loadCsv(path).empty());
}

TEST_CASE("CSV: poprawny plik recznie") {
    CHECK(loadCsv(tmpFile("uep_ok.csv", "3\n10\n0\n255\n")) == std::vector<uint8_t>{10, 0, 255});
}

TEST_CASE("CSV: bledne pliki rzucaja wyjatek") {
    CHECK_THROWS_AS(loadCsv("/nie/ma/takiego/pliku.csv"), std::runtime_error);
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e1.csv", "")), std::runtime_error);            // brak naglowka
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e2.csv", "-1\n")), std::runtime_error);        // ujemna liczba
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e3.csv", "3\n1\n2\n")), std::runtime_error);   // za malo
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e4.csv", "1\n1\n2\n")), std::runtime_error);   // za duzo
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e5.csv", "1\n256\n")), std::runtime_error);    // poza zakresem
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e6.csv", "1\n-5\n")), std::runtime_error);     // poza zakresem
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e7.csv", "1\nabc\n")), std::runtime_error);    // nie liczba
    CHECK_THROWS_AS(loadCsv(tmpFile("uep_e8.csv", "1\n12x\n")), std::runtime_error);    // smieci po liczbie
}