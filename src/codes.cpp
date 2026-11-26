#include "codes.hpp"

int length(Code c) {
	switch(c) {
	case Code::Hamming:
		return 7;
	case Code::Rep3:
		return 12;
	default:
		return 4;
	}
}

std::vector<bool> encode(Code c, uint8_t nibble) {
	switch (c) {
	case Code::Hamming:
		return hammingEncode(nibble);
	case Code::Rep3:
		return rep3Encode(nibble);
	default:
		return toBits(nibble, 4);
	}
}

uint8_t decode(Code c, const std::vector<bool>& word) {
	switch (c) {
	case Code::Hamming:
		return hammingDecode(word);
	case Code::Rep3:
		return rep3Decode(word);
	default:
		return fromBits(word);
	}
}

int cost(Strategy s) {
	return length(s.a) + length(s.b);
}