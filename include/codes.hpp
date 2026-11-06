#pragma once
#include <cstdint>
#include <vector>
#include "types.hpp"

int length(Code c);
std::vector<bool> encode(Code c, uint8_t nibble);
uint8_t decode(Code c, const std::vector<bool>& word);
int cost(Strategy s);   // length(a) + length(b)