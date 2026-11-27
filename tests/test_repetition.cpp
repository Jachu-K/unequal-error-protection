#include <doctest/doctest.h>
#include "repetition.hpp"

TEST_CASE("rep3Encode test 1") {
	const std::vector<bool> expected = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	CHECK(rep3Encode(0b0000) == expected);
}

TEST_CASE("rep3Encode test 2") {
	const std::vector<bool> expected = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0};
	CHECK(rep3Encode(0b0110) == expected);
}

TEST_CASE("rep3Decode test 1") {
	constexpr uint8_t expected = 0b1101;
	CHECK((rep3Decode({1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0}) == expected));
}

TEST_CASE("rep3Decode test 2") {
	constexpr uint8_t expected = 0b0000;
	CHECK((rep3Decode({0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0}) == expected));
}

TEST_CASE("rep3Decode rep3Encode test 1") {
	constexpr uint8_t expected = 0b0111;
	CHECK((rep3Decode(rep3Encode(expected)) == expected));
}

TEST_CASE("rep3Decode rep3Encode test 2") {
	constexpr uint8_t expected = 0b1010;
	CHECK((rep3Decode(rep3Encode(expected)) == expected));
}