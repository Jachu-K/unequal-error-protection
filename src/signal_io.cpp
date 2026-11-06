#include "signal_io.hpp"

std::vector<uint8_t> generateSine(int, double) { return {}; }
std::vector<uint8_t> generateSaw(int, int) { return {}; }
std::vector<uint8_t> generateNoise(int, std::mt19937&) { return {}; }

void saveCsv(const std::string&, const std::vector<uint8_t>&) {}
std::vector<uint8_t> loadCsv(const std::string&) { return {}; }