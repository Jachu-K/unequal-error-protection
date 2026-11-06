#include "channel.hpp"

Channel::Channel(double p, std::mt19937 rng) : p_(p), rng_(rng) {}

int Channel::corrupt(std::vector<bool>&) { return 0; }

double Channel::p() const { return p_; }