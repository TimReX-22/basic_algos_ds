#include <vector>

#include "graph.h"

class Search {
   public:
    Search() = delete;

    [[nodiscard]] static std::vector<float> djikstra(Graph g, int start_node);

    static constexpr float kInf{std::numeric_limits<float>::infinity()};
};
