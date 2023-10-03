#include "sorting.h"

template<typename T>
void Sorting<T>::InsertionSort(std::vector<T>& array) {
    for (int i = 1; i < array.size(); ++i) {
        auto current = array[i];
        int j = i - 1;
        while (j>= 0 && current < array[j]) {
            array[j+1] = array[j];
            array[j] = current;
            --j;
        }
    }
}

// Explicit instantiations
template void Sorting<int>::InsertionSort(std::vector<int>& array);