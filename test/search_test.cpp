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

TEST(FloydWarshallTest, SmallGraph) {
    auto const file{get_graph_file("small")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    auto const distances = Search::floydWarshall(g);

    ASSERT_TRUE(distances.size() == 6);
    ASSERT_TRUE(distances[0].size() == 6);

    EXPECT_FLOAT_EQ(distances[0][0], 0.0);
    EXPECT_FLOAT_EQ(distances[0][1], 2.0);
    EXPECT_FLOAT_EQ(distances[0][2], 3.0);
    EXPECT_FLOAT_EQ(distances[0][3], 8.0);
    EXPECT_FLOAT_EQ(distances[0][4], 6.0);
    EXPECT_FLOAT_EQ(distances[0][5], 9.0);

    EXPECT_FLOAT_EQ(distances[1][1], 0.0);
    EXPECT_FLOAT_EQ(distances[1][2], 1.0);
    EXPECT_FLOAT_EQ(distances[1][3], 6.0);
    EXPECT_FLOAT_EQ(distances[1][4], 4.0);
    EXPECT_FLOAT_EQ(distances[1][5], 7.0);
}