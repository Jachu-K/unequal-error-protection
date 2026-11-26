#pragma once
#include <utility>
#include <vector>
#include "bits.hpp"
#include "hamming.hpp"
#include "repetition.hpp"
#include "types.hpp"

std::vector<bool> buildFrame(const std::vector<bool>& a, const std::vector<bool>& b);

std::pair<std::vector<bool>, std::vector<bool>>
splitFrame(const std::vector<bool>& frame, Strategy s);