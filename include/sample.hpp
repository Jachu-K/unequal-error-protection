#pragma once
#include <cstdint>
#include <utility>

// v = 16a + b
std::pair<uint8_t, uint8_t> split(uint8_t v);
uint8_t join(uint8_t a, uint8_t b);
int absError(uint8_t original, uint8_t received);