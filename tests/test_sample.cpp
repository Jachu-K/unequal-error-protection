#include <doctest/doctest.h>
#include "sample.hpp"

TEST_CASE("Podzial i zlozenie probki 0xAB") {
    const auto [high, low] = split(0xAB);
    CHECK(high == 0xA);
    CHECK(low == 0xB);
    CHECK(join(high, low) == 0xAB);
}

TEST_CASE("Blad probki to roznica bezwzgledna") {
    CHECK(absError(171, 168) == 3);
    CHECK(absError(168, 171) == 3);
    CHECK(absError(171, 171) == 0);
}
