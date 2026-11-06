#pragma once
#include <utility>
#include <vector>
#include "types.hpp"

std::vector<bool> buildFrame(const std::vector<bool>& a, const std::vector<bool>& b);

std::pair<std::vector<bool>, std::vector<bool>>
splitFrame(const std::vector<bool>& frame, Strategy s);