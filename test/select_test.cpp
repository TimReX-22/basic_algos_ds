#include "select.h"

#include <gtest/gtest.h>

TEST(SelectTest, ChoosePivot) {
    std::vector<int> array{5, 3, 6, 8, 1, 4, 2, 5, 7, 6, 3, 6, 8, 9, 8};
    int pivot = choosePivot(array, array.size());
    EXPECT_EQ(pivot, 5);
}

TEST(SelectTest, SelectMin) {
    std::vector<int> array{5, 3, 6, 8, 1, 4, 2, 5, 7, 6, 3, 6, 8, 9, 8};
    int min = select(array, 1);
    EXPECT_EQ(min, 1);
}

TEST(SelectTest, SelectSecond) {
    std::vector<int> array{5, 3, 6, 8, 1, 4, 2, 5, 7, 6, 3, 6, 8, 9, 8};
    int second = select(array, 2);
    EXPECT_EQ(second, 2);
}
