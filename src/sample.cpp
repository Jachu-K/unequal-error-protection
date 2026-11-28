#include "sample.hpp"
#include <cstdlib>

std::pair<uint8_t, uint8_t> split(uint8_t v) {
    return {v >> 4, v & 0x0F};
}

uint8_t join(uint8_t a, uint8_t b) {
    return (a << 4) | (b & 0x0F);
}

int absError(uint8_t original, uint8_t received) {
    return std::abs(int(original) - int(received));
}
