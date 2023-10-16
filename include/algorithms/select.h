#include <iostream>
#include <vector>

template <typename T>
T select(std::vector<T> const& array, int k);

template <typename T>
T choosePivot(std::vector<T> const& array, int n) {
    int g = n / 5;
    std::vector<T> medians{};
    for (int i = 0; i < g; ++i) {
        if (array.begin() + i * 5 + 5 < array.end()) {
            std::vector<T> g_i = {
                array.begin() + i * 5, array.begin() + i * 5 + 5};
            medians.push_back(g_i[2]);
        } else {
            std::vector<T> g_i = {array.begin() + i * 5, array.end()};
            medians.push_back(g_i[g_i.size() / 2]);
        }
    }
    if (medians.size() == 0) {
        return array[array.size() / 2];
    }
    return select(medians, g / 2);
}

template <typename T>
T select(std::vector<T> const& array, int k) {
    int n = array.size();
    if (n == 1) {
        return array[0];
    }
    T pivot = choosePivot(array, n);
    std::vector<T> left{};
    std::vector<T> right{};
    for (auto const& a : array) {
        if (a < pivot) {
            left.push_back(a);
        } else if (a > pivot) {
            right.push_back(a);
        }
    }

    if (left.size() == k - 1) {
        return pivot;
    } else if (left.size() > k - 1) {
        return select(left, k);
    } else {
        return select(right, k - static_cast<int>(left.size()) - 1);
    }
}