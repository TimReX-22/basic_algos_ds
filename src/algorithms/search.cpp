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

    std::vector<float> d(n, kInf);
    d[s] = 0.f;

    auto compare = [](VertexDistance p1, VertexDistance p2) {
        return p1.second > p2.second;
    };

    std::priority_queue<
        VertexDistance, std::vector<VertexDistance>, decltype(compare)>
        pq(compare);
    pq.push(std::make_pair(start_node, 0.f));

    while (!pq.empty()) {
        auto [vertex, dist] = pq.top();
        pq.pop();

        assert(g.neighbors(vertex));
        auto const neighbors = *g.neighbors(vertex);

        for (auto [u, weight] : neighbors) {
            float new_dist = dist + weight;
            int idx_u = *g.idx(u);
            if (new_dist < d[idx_u]) {
                d[idx_u] = new_dist;
                pq.push(std::make_pair(u, new_dist));
            }
        }
    }
    return d;
}

std::vector<std::vector<float>> Search::floydWarshall(Graph g) {
    unsigned int const n = g.size();
    std::vector<std::vector<float>> d(n, std::vector<float>(n, kInf));
    for (int u = 0; u < n; ++u) {
        d[u][u] = 0.f;
    }

    std::vector<std::vector<float>> d_prev(n, std::vector<float>(n, kInf));
    for (auto const& v : g.vertices()) {
        int v_idx = *g.idx(v);

        assert(g.neighbors(v));
        auto const neighbors = *g.neighbors(v);

        for (auto const& [u, weight] : neighbors) {
            int u_idx = *g.idx(u);
            d_prev[v_idx][u_idx] = weight;
        }
    }

    for (auto d_i : d_prev) {
        for (auto d : d_i) {
            std::cout << d << " ";
        }
        std::cout << "\n";
    }

    for (auto const k : g.vertices()) {
        for (auto const u : g.vertices()) {
            for (auto const v : g.vertices()) {
                if (u == v) {
                    continue;
                }
                int u_idx = *g.idx(u);
                int v_idx = *g.idx(v);
                int k_idx = *g.idx(k);

                d[u_idx][v_idx] = std::min(
                    d_prev[u_idx][v_idx],
                    d_prev[u_idx][k_idx] + d_prev[k_idx][v_idx]);
            }
        }
        d_prev = d;
    }

    for (auto d_i : d_prev) {
        for (auto d : d_i) {
            std::cout << d << " ";
        }
        std::cout << "\n";
    }

    return d;
}
