#pragma once
#include <cstdint>
#include <random>
#include <string>
#include <vector>


std::vector<uint8_t> generateSine(int n, double period);
std::vector<uint8_t> generateSaw(int n, int period);
std::vector<uint8_t> generateNoise(int n, std::mt19937& rng);

void saveCsv(const std::string& path, const std::vector<uint8_t>& samples);
std::vector<uint8_t> loadCsv(const std::string& path);   // rzuca wyjątek z numerem linii przy złych danyc