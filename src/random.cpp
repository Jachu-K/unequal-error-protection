#include "random.hpp"

std::mt19937 makeRng(uint32_t masterSeed, RngStream stream) {
    std::seed_seq seq{masterSeed, static_cast<uint32_t>(stream)};
    return std::mt19937(seq);
}

