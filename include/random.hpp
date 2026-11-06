#pragma once
#include <cstdint>
#include <random>

// Kazdy element losowy ma wlasny strumien, z jednego seeda
enum class RngStream : uint32_t { Signal = 1, Channel = 2 };

std::mt19937 makeRng(uint32_t masterSeed, RngStream stream);