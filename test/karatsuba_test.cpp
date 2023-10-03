#include "karatsuba.h"

#include "gtest/gtest.h"

TEST(KaratsubaTests, SimpleMultiplacations) {
    int x = 22;
    int y = 44;
    int res = Multiplication::Karatsuba(x, y, 2);
    EXPECT_EQ(res, x * y);

    x = 123;
    y = 345;
    res = Multiplication::Karatsuba(x, y, 2);
    EXPECT_EQ(res, x * y);
}

TEST(KaratsubaTests, LargeMultiplacations) {
    uint64_t x = 12345678;
    uint64_t y = 99999999;
    uint64_t res = Multiplication::Karatsuba(x, y, 8);
    EXPECT_EQ(res, x * y);

    x = 98765432;
    y = 10000000;
    res = Multiplication::Karatsuba(x, y, 8);
    EXPECT_EQ(res, x * y);
}