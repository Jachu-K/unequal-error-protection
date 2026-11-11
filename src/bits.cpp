#include "bits.hpp"

#include <algorithm>
#include <stdexcept>

std::vector<bool> toBits(uint8_t nibble, int n) {
    if (n < 0 || n > 8) throw std::invalid_argument("toBits : n poza [0,8]");
    std::vector<bool> result(n);
    for (int i=0;i<n;i++) {
        result[i] = nibble & (1<<i);
    }
    std::reverse(result.begin(),result.end());
    return result;
}
uint8_t fromBits(const std::vector<bool>& bits) {
    if (bits.size()>8) throw std::invalid_argument("fromBits : wiecej niz 8 bitow");
    uint8_t res = 0;
    for (auto bit : bits) {
        res<<=1;
        if (bit)res++;
    }
    return res;
}