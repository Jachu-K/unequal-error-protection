#include "channel.hpp"
#include <stdexcept>

Channel::Channel(double p, std::mt19937 rng) : p_(p), rng_(rng) {
    if (!(p>=0.0 && p<=0.5)) {
        throw std::invalid_argument("Channel: p musi być w [0,0.5]");
    }
}

int Channel::corrupt(std::vector<bool>& bits) {
    std::uniform_real_distribution<double> losuj(0.0,1.0);
    int flips_number=0;
    for (auto && bit : bits) {
        if (losuj(rng_) < p_) {
            bit=!bit;
            flips_number++;
        }
    }
    return flips_number;
}

double Channel::p() const { return p_; }