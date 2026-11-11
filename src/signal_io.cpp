#include "signal_io.hpp"

std::vector<uint8_t> generateSine(int n, double period) {
    if (n < 0) throw std::invalid_argument("generateSine: n < 0");
    if (period <= 0) throw std::invalid_argument("generateSine: period <= 0");

    std::vector<uint8_t> s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        double x = 127.5 + 127.5 * std::sin(2.0 * std::numbers::pi * i / period);
        long v = std::lround(x);
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        s.push_back(static_cast<uint8_t>(v));
    }
    return s;
}
std::vector<uint8_t> generateSaw(int n, int period) {
    if (n < 0) throw std::invalid_argument("generateSaw: n < 0");
    if (period <= 0) throw std::invalid_argument("generateSaw: period <= 0");

    std::vector<uint8_t> s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        int v = (i % period) * 256 / period;
        s.push_back(static_cast<uint8_t>(v));
    }
    return s;
}
std::vector<uint8_t> generateNoise(int n, std::mt19937& rng) {
    if (n < 0) throw std::invalid_argument("generateNoise: n < 0");

    std::uniform_int_distribution<int> dist(0, 255);
    std::vector<uint8_t> s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s.push_back(static_cast<uint8_t>(dist(rng)));
    }
    return s;
}

void saveCsv(const std::string&, const std::vector<uint8_t>&) {}
std::vector<uint8_t> loadCsv(const std::string&) { return {}; }