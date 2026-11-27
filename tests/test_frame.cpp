#include <doctest/doctest.h>
#include "frame.hpp"

TEST_CASE("buildFrame test") {
	const std::vector<bool> expected{0, 0, 0, 1, 0, 0, 1, 1};
	CHECK(buildFrame({0, 0, 0, 1}, {0, 0, 1, 1}) == expected);
}

TEST_CASE("splitFrame None test") {
	const std::pair <std::vector<bool>, std::vector<bool>> expected{{0, 1, 0, 1}, {1, 1, 1, 0}};
	CHECK(splitFrame({0, 1, 0, 1, 1, 1, 1, 0}, {.a = Code::None, .b = Code::None}) == expected);
}

TEST_CASE("splitFrame Hamming test") {
	const std::pair <std::vector<bool>, std::vector<bool>> expected{hammingEncode(0b0101), hammingEncode(0b1110)};
	CHECK(splitFrame({0, 1, 0, 1, 1, 1, 1, 0}, {.a = Code::Hamming, .b = Code::Hamming}) == expected);
}

TEST_CASE("splitFrame repetition test") {
	const std::pair <std::vector<bool>, std::vector<bool>> expected{rep3Encode(0b0101), rep3Encode(0b1110)};
	CHECK(splitFrame({0, 1, 0, 1, 1, 1, 1, 0}, {.a = Code::Rep3, .b = Code::Rep3}) == expected);
}

TEST_CASE("splitFrame buildFrame Hamming repetition test") {
	const std::pair <std::vector<bool>, std::vector<bool>> expected{hammingEncode(0b1000), rep3Encode(0b0001)};
	CHECK(splitFrame(buildFrame({1, 0, 0, 0}, {0, 0, 0, 1}), {.a = Code::Hamming, .b = Code::Rep3}) == expected);
}