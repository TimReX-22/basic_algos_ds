#include <algorithm>
#include <cmath>
#include <iostream>

class Multiplication {
    public:
    Multiplication() = delete;
    [[nodiscard]] static uint64_t Karatsuba(uint64_t x, uint64_t y, int n) {
        if (n == 1) {
            return x * y;
        }
        
        uint64_t pow_of_10 = static_cast<uint64_t>(std::pow(10, n / 2));
        uint64_t a = x / pow_of_10;
        uint64_t b = x % pow_of_10;
        uint64_t c = y / pow_of_10;
        uint64_t d = y % pow_of_10;

        uint64_t z_1 = Karatsuba(a, c, n/2);
        uint64_t z_2 = Karatsuba(b, d, n/2);
        uint64_t z_3 = Karatsuba(a + b, c + d, n/2);
        uint64_t z_4 = z_3 - z_2 - z_1;
        return z_1 * static_cast<uint64_t>(std::pow(10, n)) + z_4 * pow_of_10 + z_2;
    }
};