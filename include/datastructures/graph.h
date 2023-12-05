#pragma once

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "json.hpp"

using json = nlohmann::json;

class Graph {
   public:
    Graph() = default;
    Graph(bool directed) : adj_list_(), val_to_idx_(), is_directed_(directed) {}

    static std::optional<Graph> createGraphFromJson(
        std::string const& filename, bool const is_directed) {
        if (!std::filesystem::exists(filename)) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return std::nullopt;
        }
        std::ifstream file(filename);
        if (!file.good()) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return std::nullopt;
        }

        json j;
        file >> j;

        Graph g(is_directed);

        for (auto& element : j.items()) {
            int vertex = std::stoi(element.key());
            g.addVertex(vertex);

            for (auto& neighbor : element.value().items()) {
                int neighbor_vertex = std::stoi(neighbor.key());
                float weight = neighbor.value();

                if (!g.containsVertex(neighbor_vertex)) {
                    g.addVertex(neighbor_vertex);
                }

                if (!g.addEdge(vertex, neighbor_vertex, weight)) {
                    return std::nullopt;
                };
            }
        }

        return g;
    }

    bool addVertex(int val) {
        if (containsVertex(val)) {
            return false;
        }
        int n = adj_list_.size();
        val_to_idx_[val] = n;
        adj_list_.push_back({});
        vertices_.push_back(val);
        return true;
    }

    bool containsVertex(int v) const {
        return val_to_idx_.find(v) != val_to_idx_.end();
    }

    bool addEdge(int v, int u, double weight) {
        if (v == u) {
            return false;
        }

        if (!containsVertex(v) || !containsVertex(u)) {
            return false;
        }

        int idx_v = val_to_idx_[v];
        int idx_u = val_to_idx_[u];

        adj_list_[idx_v].push_back(std::make_pair(u, weight));

        if (!is_directed_) {
            adj_list_[idx_u].push_back(std::make_pair(v, weight));
        }

        return true;
    }

    std::optional<std::vector<std::pair<int, float>>> neighbors(int v) {
        if (!containsVertex(v)) {
            return std::nullopt;
        }
        int idx = val_to_idx_[v];
        return adj_list_[idx];
    }

    std::optional<float> weight(int v, int u) {
        if (!containsVertex(v) || !containsVertex(u)) {
            return std::nullopt;
        }
        int idx_v = val_to_idx_[v];

        auto edges_v = adj_list_[idx_v];

        for (auto edge : edges_v) {
            if (edge.first == u) {
                return edge.second;
            }
        }

        return std::nullopt;
    }

    std::vector<int> vertices() const { return vertices_; }

    unsigned int const size() const { return adj_list_.size(); }

    std::optional<int> idx(int val) {
        return containsVertex(val) ? std::optional<int>(val_to_idx_[val])
                                   : std::nullopt;
    }

   private:
    std::vector<std::vector<std::pair<int, float>>> adj_list_;
    std::unordered_map<int, int> val_to_idx_;
    std::vector<int> vertices_;
    bool const is_directed_ = false;
};