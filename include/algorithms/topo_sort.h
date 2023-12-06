#pragma once

#include "algorithm"
#include "search.h"

inline std::vector<int> topoSort(Graph g) {
    if (g.size() == 0) {
        return {};
    }
    std::vector<int> order;
    std::unordered_set<int> visited;
    int const start = g.vertices().at(0);

    Search::DFS(g, order, visited, start);

    std::reverse(order.begin(), order.end());
    return order;
}