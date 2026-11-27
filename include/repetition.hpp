#pragma once
#include <cstdint>
#include <vector>
#include "bits.hpp"

// kodowanie powtorzeniowe x3
std::vector<bool> rep3Encode(uint8_t nibble);
uint8_t rep3Decode(const std::vector<bool>& word);
