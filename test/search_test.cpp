#include "search.h"

#include <gtest/gtest.h>

TEST(DjikstraTest, SmallGraph) {
    std::string graph_file{"test/resources/graph_small.json"};
    auto graph_json{Graph::createGraphFromJson(graph_file)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    auto distances = Search::djikstra(g, 1);
}