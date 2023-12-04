#include "search.h"

#include <iostream>
#include <queue>
#include <unordered_set>

using VertexDistance = std::pair<int, float>;

std::vector<float> Search::djikstra(Graph g, int start_node) {
    unsigned int const n = g.size();
    if (n == 0) {
        return {};
    }

    int s = 0;
    if (auto start_idx = g.idx(start_node); !start_idx) {
        return {};
    } else {
        s = *start_idx;
    }

    std::vector<float> d(n, std::numeric_limits<float>::infinity());
    d[s] = 0.f;

    auto compare = [](VertexDistance p1, VertexDistance p2) {
        return p1.second > p2.second;
    };

    std::priority_queue<
        VertexDistance, std::vector<VertexDistance>, decltype(compare)>
        pq(compare);

    for (auto const v : g.vertices()) {
        if (v == start_node) {
            pq.push(std::make_pair(v, 0.f));
        } else {
            pq.push(std::make_pair(v, std::numeric_limits<float>::infinity()));
        }
    }

    std::unordered_set<int> visited;

    while (!pq.empty()) {
        auto [vertex, dist] = pq.top();
        pq.pop();

        std::cout << "v = " << vertex << ", d =  " << dist << "\n";

        if (visited.find(vertex) != visited.end()) {
            continue;
        }
        visited.insert(vertex);

        if (!g.neighbors(vertex)) {
            std::cout << "fail\n";
            continue;
        }

        for (auto [u, weight] : *g.neighbors(vertex)) {
            float new_dist = dist + weight;
            int idx_u = *g.idx(u);
            if (new_dist < d[idx_u]) {
                d[idx_u] = new_dist;
                pq.push(std::make_pair(u, new_dist));
            }
        }
    }
    return {};
}
