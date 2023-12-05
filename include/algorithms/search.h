#include <vector>

#include "graph.h"

class Search {
   public:
    Search() = delete;

    /**
     * @brief runs Djikstr's algorithm to find the shortest path from start_node
     * in Grapg g. Uses std::priority_queue, which is implemented using a binary
     * min-heap. The time complexity is O((|V| + |E|)*log(|V|)).
     *
     * @param g Graph
     * @param start_node Value of the starting node
     * @return std::vector<float> array containing the shortest path from the
     * starting node to every other node in the graph
     */
    [[nodiscard]] static std::vector<float> djikstra(Graph g, int start_node);

    /**
     * @brief runs the Floyd-Warshall algorithm to find All-Pairs-Shortest-Path
     * in the Graph g
     *
     * @param g Graph
     * @return std::vector<std::vector<float>> 2-D array, where D[i][j] is the
     * length of the shortest path from vertex i to vertex j
     */
    [[nodiscard]] static std::vector<std::vector<float>> floydWarshall(Graph g);

    static constexpr float kInf{std::numeric_limits<float>::infinity()};
};
