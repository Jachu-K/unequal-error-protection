#include <doctest/doctest.h>
#include "hamming.hpp"

TEST_CASE("Hamming koduje i odkodowuje 1011") {
    const std::vector<bool> expected{0, 1, 1, 0, 0, 1, 1};
    CHECK(hammingEncode(11) == expected);
    CHECK(hammingDecode(expected) == 11);
}

TEST_CASE("Hamming poprawia jeden blad na dowolnej pozycji") {
    const std::vector<bool> encoded{0, 1, 1, 0, 0, 1, 1};
    for (std::size_t i = 0; i < encoded.size(); ++i) {
        auto received = encoded;
        received[i].flip();
        CHECK(hammingDecode(received) == 11);
    }
}
