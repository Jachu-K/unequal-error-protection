#include <doctest/doctest.h>
#include <vector>
#include "bits.hpp"

TEST_CASE("toBits(12, 4) == 1100") {
    const std::vector<bool> expected{1, 1, 0, 0};
    CHECK(toBits(12, 4) == expected);
}

TEST_CASE("toBits(3, 8) ma zera z przodu") {
    const std::vector<bool> expected{0, 0, 0, 0, 0, 0, 1, 1};
    CHECK(toBits(3, 8) == expected);
}

TEST_CASE("fromBits(toBits(x, 8)) == x dla wszystkich 0-255") {
    for (int x = 0; x <= 255; x++) {
        int y = x;
        CHECK(int(fromBits(toBits(static_cast<uint8_t>(x), 8))) == y);
    }
}