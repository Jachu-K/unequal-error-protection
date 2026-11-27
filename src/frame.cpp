#include "frame.hpp"

std::vector<bool> buildFrame(const std::vector<bool>& a, const std::vector<bool>& b) {
    auto result = a;
    result.insert( result.end(), b.begin(), b.end() );
    return result;
}

std::pair<std::vector<bool>, std::vector<bool>>
splitFrame(const std::vector<bool>& frame, Strategy s) {
    auto a = std::vector(frame.begin(), frame.begin() + 4);
    auto b = std::vector(frame.begin() + 4, frame.end());
    const auto a_bits = fromBits(a);
    const auto b_bits = fromBits(b);

	a = encode(s.a, a_bits);
	b = encode(s.b, b_bits);

    return std::make_pair(a, b);
}