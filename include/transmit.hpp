#pragma once
#include <cstdint>
#include <vector>
#include "channel.hpp"
#include "types.hpp"

struct TransmitResult {
    uint8_t original = 0;
    uint8_t received = 0;
    std::vector<bool> sent;      // ramka przed kanalem
    std::vector<bool> arrived;   // ramka po kanale
    int flips = 0;               // ile bitow kanal odwrocil
};

TransmitResult transmitSample(uint8_t v, Strategy s, Channel& ch);