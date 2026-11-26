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

    switch (s.a) {
    case Code::Hamming:
        a = hammingEncode(a_bits);
        break;
    case Code::Rep3:
    	a = rep3Encode(a_bits);
    	break;
	default: ;
    }

	switch (s.b) {
	case Code::Hamming:
		b = hammingEncode(b_bits);
		break;
	case Code::Rep3:
		b = rep3Encode(b_bits);
		break;
	default: ;
	}

    return std::make_pair(a, b);
}