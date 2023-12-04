#include <vector>

#include "graph.h"

class Search {
   public:
    Search() = delete;

    [[nodiscard]] static std::vector<float> djikstra(Graph g, int start_node);
};
