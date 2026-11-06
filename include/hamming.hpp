#pragma once
#include <cstdint>
#include <vector>

// przyjmuje wiadomosc (4 bity) zwraca zakodowana kodem hamminga
std::vector<bool> hammingEncode(uint8_t nibble);
uint8_t hammingDecode(const std::vector<bool>& word);