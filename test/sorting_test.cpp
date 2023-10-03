#include "sorting.h" 

#include <gtest/gtest.h>


TEST(InsertionSortTest, EmptyArray) {
    std::vector<int> emptyArray;
    Sorting<int>::InsertionSort(emptyArray);
    EXPECT_TRUE(emptyArray.empty());
}

TEST(InsertionSortTest, SortedArray) {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5};
    Sorting<int>::InsertionSort(sortedArray);
    for (int i = 0; i < sortedArray.size(); ++i) {
        EXPECT_EQ(sortedArray[i], i + 1);
    }
}

TEST(InsertionSortTest, ReverseSortedArray) {
    std::vector<int> reverseSortedArray = {5, 4, 3, 2, 1};
    Sorting<int>::InsertionSort(reverseSortedArray);
    for (int i = 0; i < reverseSortedArray.size(); ++i) {
        EXPECT_EQ(reverseSortedArray[i], i + 1);
    }
}

TEST(InsertionSortTest, RandomArray) {
    std::vector<int> randomArray = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::vector<int> expectedSortedArray = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
    Sorting<int>::InsertionSort(randomArray);
    EXPECT_EQ(randomArray, expectedSortedArray);
}

TEST(InsertionSortTest, DuplicateElements) {
    std::vector<int> duplicateArray = {2, 4, 2, 1, 3, 1, 4, 5};
    std::vector<int> expectedSortedArray = {1, 1, 2, 2, 3, 4, 4, 5};
    Sorting<int>::InsertionSort(duplicateArray);
    EXPECT_EQ(duplicateArray, expectedSortedArray);
}