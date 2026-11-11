#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdint>

#include "bits.hpp"
#include "channel.hpp"
#include "random.hpp"
#include "signal_io.hpp"

constexpr bool demo_gen_transmit = true;    // demo czesci z generowaniem i transmisja probek

static void printBits(const std::vector<bool>& bits) {
    for (auto b : bits) std::cout << (b ? '1' : '0');
}

static void demoGenTransmit() {
    const uint32_t seed = 232333;
    const double p = 0.05;

    std::vector<uint8_t> samples = generateSaw(15, 6);

    std::mt19937 rngSignal = makeRng(seed, RngStream::Signal);
    std::vector<uint8_t> randomsample = generateNoise(samples.size(), rngSignal);

    Channel ch(p, makeRng(seed, RngStream::Channel));
    std::cout << "Demo: " << samples.size() << " probek, p = " << p
              << " seed = " << seed << " bez kodowania\n\n";
    std::cout << " i  oryg  wyslane   odebrane  odtw  blad  flips\n";

    int totalFlips = 0;
    for (std::size_t i = 0; i < samples.size(); i++) {
        uint8_t original = (i > 8) ? randomsample[i] : samples[i];
        std::vector<bool> sent = toBits(original, 8);
        std::vector<bool> arrived = sent;            // kopia ktora kanal popsuje
        int flips = ch.corrupt(arrived);
        uint8_t received = fromBits(arrived);
        int err = std::abs(int(received) - int(original));
        totalFlips += flips;

        std::cout << std::setw(2) << i << "  " << std::setw(4) << int(original) << "  ";
        printBits(sent);
        std::cout << "  ";
        printBits(arrived);
        std::cout << "  " << std::setw(4) << int(received)
                  << "  " << std::setw(4) << err
                  << "  " << std::setw(5) << flips << '\n';
    }

    std::cout << "\nLacznie przeklamanych bitow: " << totalFlips
              << " z " << samples.size() * 8 << '\n';
}

int main() {
    std::cout << "unequal-error-protection\n\n";

    if constexpr (demo_gen_transmit) {
        demoGenTransmit();
    }

    return 0;
}