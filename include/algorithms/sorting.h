#pragma once

#include <vector>

template <typename T>
class Sorting {
   public:
    Sorting() = delete;

    // Time Complexitiy: O(n^2)
    static void InsertionSort(std::vector<T>& array);
    // Time Complexitiy: O(n*log(n))
    static void MergeSort(std::vector<T>& array);
    // Time Complexitiy: O(n"log(n))
    static void QuickSort(std::vector<T>& array);

   private:
    [[nodiscard]] static std::vector<T> merge(
        std::vector<T> const& array_L, std::vector<T> const& array_R);
};
