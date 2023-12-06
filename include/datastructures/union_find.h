#pragma once

#include <vector>

class UnionFind {
   public:
    UnionFind(int size) {
        parent_.resize(size);
        rank_.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent_[i] = i;
        }
    }

    void makeSet(int x) {
        if (x >= parent_.size()) {
            parent_.resize(x + 1);
            rank_.resize(x + 1);
        }

        parent_[x] = x;
        rank_[x] = 0;
    }

    int find(int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }

    void merge(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot) {
            return;
        }

        if (rank_[xRoot] < rank_[yRoot]) {
            parent_[xRoot] = yRoot;
        } else if (rank_[xRoot] > rank_[yRoot]) {
            parent_[yRoot] = xRoot;
        } else {
            parent_[yRoot] = xRoot;
            rank_[xRoot]++;
        }
    }

   private:
    std::vector<int> parent_;
    std::vector<int> rank_;
};
