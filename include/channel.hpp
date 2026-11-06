#pragma once
#include <random>
#include <vector>

class Channel {
public:
    Channel(double p, std::mt19937 rng);

    // odwraca kazdy bit z prawd. p
    int corrupt(std::vector<bool>& bits);

    double p() const;

private:
    double p_;
    std::mt19937 rng_;
};