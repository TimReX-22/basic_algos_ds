#include "sorting.h"

#include <stdio.h>

#include <random>

template <typename T>
void Sorting<T>::InsertionSort(std::vector<T>& array) {
    for (int i = 1; i < array.size(); ++i) {
        auto current = array[i];
        int j = i - 1;
        while (j >= 0 && current < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = current;
    }
}
template <typename T>
void Sorting<T>::MergeSort(std::vector<T>& array) {
    unsigned int n = array.size();
    if (n <= 1) {
        return;
    }
    std::vector<T> left{array.begin(), array.begin() + n / 2};
    std::vector<T> right{array.begin() + n / 2, array.end()};

    MergeSort(left);
    MergeSort(right);

    array = merge(left, right);
}

template <typename T>
std::vector<T> Sorting<T>::merge(
    std::vector<T> const& array_L, std::vector<T> const& array_R) {
    std::vector<T> res{};
    int n_L = array_L.size();
    int n_R = array_R.size();
    int i_L = 0, i_R = 0;

    while (i_L < n_L || i_R < n_R) {
        if (array_L[i_L] <= array_R[i_R]) {
            res.push_back(array_L[i_L]);
            ++i_L;
            if (i_L == n_L) {
                res.insert(res.end(), array_R.begin() + i_R, array_R.end());
                break;
            }
        } else {
            res.push_back(array_R[i_R]);
            ++i_R;
            if (i_R == n_R) {
                res.insert(res.end(), array_L.begin() + i_L, array_L.end());
                break;
            }
        }
    }

    return res;
}

template <typename T>
void Sorting<T>::QuickSort(std::vector<T>& array) {
    int n = array.size();
    if (n <= 1) {
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, n - 1);

    int pivot = distrib(gen);

    std::vector<T> left{};
    std::vector<T> right{};

    for (int i = 0; i < n; ++i) {
        if (i != pivot) {
            if (array[i] <= array[pivot]) {
                left.push_back(array[i]);
            } else {
                right.push_back(array[i]);
            }
        }
    }

    QuickSort(left);
    QuickSort(right);

    left.push_back(array[pivot]);
    left.insert(left.end(), right.begin(), right.end());

    array = left;
}

// Explicit instantiations
template void Sorting<int>::InsertionSort(std::vector<int>& array);
template void Sorting<int>::MergeSort(std::vector<int>& array);
template void Sorting<int>::QuickSort(std::vector<int>& array);