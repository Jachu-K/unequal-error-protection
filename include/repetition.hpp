#pragma once
#include <cstdint>
#include <vector>

// kodowanie powtorzeniowe x3
std::vector<bool> rep3Encode(uint8_t nibble);
uint8_t rep3Decode(const std::vector<int>& word);

// brak kodu
std::vector<bool> noneEncode(uint8_t nibble);
uint8_t noneDecode(const std::vector<int>& word);