#include <doctest/doctest.h>
#include <algorithm>
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