#include "repetition.hpp"

std::vector<bool> rep3Encode(uint8_t nibble) {
	const auto zeros = {false, false, false};
	const auto ones = {true, true, true};
	std::vector<bool> result = {};

	for (int i = 0; i < 4; i++) {
		if ((nibble & (1 << i)) == 0) {
			result.insert(result.begin(), zeros.begin(), zeros.end());
		}
		else {
			result.insert(result.begin(), ones.begin(), ones.end());
		}
	}

	return result;
}

uint8_t rep3Decode(const std::vector<bool>& word) {
	std::vector<bool> result = {};

	for (int i = 0; i < 12; i += 3) {
		if (word[i] == word[i + 1] || word[i] == word[i + 2]) {
			result.push_back(word[i]);
		}
		else {
			result.push_back(word[i + 1]);
		}
	}

	return fromBits(result);
}
