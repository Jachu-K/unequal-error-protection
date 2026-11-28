#include "hamming.hpp"
#include "bits.hpp"
#include <stdexcept>

std::vector<bool> hammingEncode(uint8_t nibble) {
    const auto data = toBits(nibble, 4);
    const bool a = data[0], b = data[1], c = data[2], d = data[3];
    // Parity bits occupy positions 1, 2 and 4 (counting from 1).
    return {bool(a ^ b ^ d), bool(a ^ c ^ d), a, bool(b ^ c ^ d), b, c, d};
}

uint8_t hammingDecode(const std::vector<bool>& word) {
    if (word.size() != 7) throw std::invalid_argument("hammingDecode: oczekiwano 7 bitow");

    // XOR of the positions of set bits gives the position of a single error.
    int errorPosition = 0;
    for (int position = 1; position <= 7; ++position) {
        if (word[position - 1]) errorPosition ^= position;
    }

    auto corrected = word;
    if (errorPosition != 0) corrected[errorPosition - 1].flip();
    return fromBits({corrected[2], corrected[4], corrected[5], corrected[6]});
}
