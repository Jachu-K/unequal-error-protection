#pragma once

// Metoda kodowania połówki
enum class Code { None, Hamming, Rep3 };

// Strategia : para metod kodowania
struct Strategy {
    Code a;
    Code b;
};