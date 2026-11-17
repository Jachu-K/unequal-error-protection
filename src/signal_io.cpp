#include "signal_io.hpp"
#include <cmath>
#include <fstream>
#include <numbers>
#include <stdexcept>

std::vector<uint8_t> generateSine(int n, double period) {
    if (n < 0) throw std::invalid_argument("generateSine: n < 0");
    if (period <= 0) throw std::invalid_argument("generateSine: period <= 0");

    std::vector<uint8_t> s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        double x = 127.5 + 127.5 * std::sin(2.0 * std::numbers::pi * i / period);
        long v = std::lround(x);
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        s.push_back(static_cast<uint8_t>(v));
    }
    return s;
}
std::vector<uint8_t> generateSaw(int n, int period) {
    if (n < 0) throw std::invalid_argument("generateSaw: n < 0");
    if (period <= 0) throw std::invalid_argument("generateSaw: period <= 0");

    std::vector<uint8_t> s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        int v = (i % period) * 256 / period;
        s.push_back(static_cast<uint8_t>(v));
    }
    return s;
}
std::vector<uint8_t> generateNoise(int n, std::mt19937& rng) {
    if (n < 0) throw std::invalid_argument("generateNoise: n < 0");

    std::uniform_int_distribution<int> dist(0, 255);
    std::vector<uint8_t> s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s.push_back(static_cast<uint8_t>(dist(rng)));
    }
    return s;
}

// pierwsza linia oznacza ile probek
void saveCsv(const std::string& path, const std::vector<uint8_t>& samples) {
    std::ofstream file(path);
    if (!file) throw std::runtime_error("saveCsv: nie mozna otworzyc pliku " + path);

    file << samples.size() << "\n";
    for (uint8_t v : samples) file << int(v) << '\n';

    if (!file) throw std::runtime_error("saveCsv: blad zapisu do pliku " + path);
}

std::vector<uint8_t> loadCsv(const std::string& path) {
    std::ifstream file(path);
    if (!file) throw std::runtime_error("loadCsv: nie mozna otworzyc pliku " + path);

    int samples_count = 0;
    if (!(file >> samples_count))
        throw std::runtime_error("loadCsv: pierwsza linia musi byc liczba probek");
    if (samples_count < 0) throw std::runtime_error("loadCsv: mniej niz 0 probek w pliku");

    std::vector<uint8_t> samples;
    std::string token;

    for (int i = 0; i < samples_count; i++) {
        std::string where = "loadCsv: probka nr " + std::to_string(i + 1) + ": ";

        if (!(file >> token))
            throw std::runtime_error(where + "brak, w pliku jest tylko " + std::to_string(i) + " probek");

        std::size_t pos = 0;
        int val = 0;
        try {
            val = std::stoi(token, &pos);
        } catch (const std::exception&) {
            pos = 0;
        }
        if (pos == 0 || pos != token.size())
            throw std::runtime_error(where + "'" + token + "' nie jest liczba calkowita");
        if (val < 0 || val > 255)
            throw std::runtime_error(where + "wartosc " + token + " poza zakresem 0-255");

        samples.push_back(static_cast<uint8_t>(val));
    }

    if (file >> token)
        throw std::runtime_error("loadCsv: w pliku jest wiecej probek niz " + std::to_string(samples_count));

    return samples;
}