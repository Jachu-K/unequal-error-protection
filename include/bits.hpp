#pragma once
#include <cstdint>
#include <vector>

// najstarszy bit pierwszy
std::vector<bool> toBits(uint8_t value, int n);
uint8_t fromBits(const std::vector<bool>& bits);