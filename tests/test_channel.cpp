#include <doctest/doctest.h>
#include "channel.hpp"
#include "random.hpp"

static std::vector<bool> pattern(std::size_t n) {
    std::vector<bool> res(n);
    while (n--) {
        res[n] = n%2;
    }
    return res;
}

TEST_CASE("p spoza [0, 0.5] rzuca wyjatek") {
    CHECK_THROWS_AS(Channel(-0.1, makeRng(42, RngStream::Channel)), std::invalid_argument);
    CHECK_THROWS_AS(Channel(0.51,  makeRng(42, RngStream::Channel)), std::invalid_argument);
}

TEST_CASE("p na granicach [0, 0.5] jest poprawne") {
    CHECK_NOTHROW(Channel(0.0, makeRng(42, RngStream::Channel)));
    CHECK_NOTHROW(Channel(0.5, makeRng(42, RngStream::Channel)));
}

TEST_CASE("ten sam seed daje ten sam wynik") {
    Channel ch1(0.2, makeRng(42, RngStream::Channel));
    Channel ch2(0.2, makeRng(42, RngStream::Channel));
    std::vector<bool> a = pattern(1000);
    std::vector<bool> b = pattern(1000);

    ch1.corrupt(a);
    ch2.corrupt(b);

    CHECK(a == b);
}

TEST_CASE("p = 0.0 nie zmienia wektora") {
    Channel ch1(0.0, makeRng(42, RngStream::Channel));
    std::vector<bool> a = pattern(10101);
    std::vector<bool> b = a;
    ch1.corrupt(b);

    CHECK(a==b);

}