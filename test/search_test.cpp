#include "search.h"

#include <gtest/gtest.h>

TEST(DjikstraTest, SmallGraph) {
    auto const file{get_graph_file("small")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    auto distances = Search::djikstra(g, 1);

    ASSERT_TRUE(distances.size() == 6);
    EXPECT_FLOAT_EQ(distances[0], 0.0);
    EXPECT_FLOAT_EQ(distances[1], 2.0);
    EXPECT_FLOAT_EQ(distances[2], 3.0);
    EXPECT_FLOAT_EQ(distances[3], 8.0);
    EXPECT_FLOAT_EQ(distances[4], 6.0);
    EXPECT_FLOAT_EQ(distances[5], 9.0);
}

TEST(DjikstraTest, LargeGraph) {
    auto const file{get_graph_file("large")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    auto distances = Search::djikstra(g, 1);

    ASSERT_TRUE(distances.size() == 9);
    EXPECT_FLOAT_EQ(distances[0], 0.0);
    EXPECT_FLOAT_EQ(distances[1], 2.0);
    EXPECT_FLOAT_EQ(distances[2], 3.0);
}