#pragma once

#include <algorithm>
#include <vector>

#include "graph.h"
#include "union_find.h"

std::vector<std::pair<int, int>> Kruskal(Graph g) {
    if (g.size() == 0) {
        return {};
    }

    std::vector<Graph::EdgeWeight> edges{g.edges()};

    auto compare = [](Graph::EdgeWeight const& e1,
                      Graph::EdgeWeight const& e2) {
        return e1.second < e2.second;
    };

    std::vector<std::pair<int, int>> MST;

    std::sort(edges.begin(), edges.end(), compare);

    UnionFind uf(g.size());

    for (Graph::EdgeWeight const& edge : edges) {
        int const u = edge.first.first;
        int const v = edge.first.second;
        int const idx_u = *g.idx(u);
        int const idx_v = *g.idx(v);
        if (uf.find(idx_u) != uf.find(idx_v)) {
            MST.push_back(std::make_pair(u, v));
            uf.merge(idx_u, idx_v);
        }
    }
    return MST;
}