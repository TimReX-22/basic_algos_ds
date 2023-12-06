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

TEST(DjikstraTest, CycleGraph) {
    auto const file{get_graph_file("cycle")};
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

TEST(BFSTest, SmallGraph) {
    auto const file{get_graph_file("small")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    EXPECT_TRUE(Search::BFS(g, 1));
    EXPECT_TRUE(Search::BFS(g, 2));
    EXPECT_TRUE(Search::BFS(g, 3));
    EXPECT_TRUE(Search::BFS(g, 4));
    EXPECT_TRUE(Search::BFS(g, 5));
    EXPECT_TRUE(Search::BFS(g, 6));
    EXPECT_FALSE(Search::BFS(g, 7));
}

TEST(BFSTest, LargeGraph) {
    auto const file{get_graph_file("large")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    EXPECT_TRUE(Search::BFS(g, 1));
    EXPECT_TRUE(Search::BFS(g, 2));
    EXPECT_TRUE(Search::BFS(g, 3));
    EXPECT_TRUE(Search::BFS(g, 4));
    EXPECT_TRUE(Search::BFS(g, 5));
    EXPECT_TRUE(Search::BFS(g, 6));
    EXPECT_TRUE(Search::BFS(g, 7));
    EXPECT_TRUE(Search::BFS(g, 8));
    EXPECT_TRUE(Search::BFS(g, 9));
    EXPECT_FALSE(Search::BFS(g, 10));
}

TEST(BFSTest, CycleGraph) {
    auto const file{get_graph_file("cycle")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    EXPECT_TRUE(Search::BFS(g, 1));
    EXPECT_TRUE(Search::BFS(g, 2));
    EXPECT_TRUE(Search::BFS(g, 3));
    EXPECT_TRUE(Search::BFS(g, 4));
    EXPECT_TRUE(Search::BFS(g, 5));
    EXPECT_TRUE(Search::BFS(g, 6));
    EXPECT_FALSE(Search::BFS(g, 7));
}

TEST(DFSTest, SmallGraph) {
    auto const file{get_graph_file("small")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    EXPECT_TRUE(Search::DFS(g, 1));
    EXPECT_TRUE(Search::DFS(g, 2));
    EXPECT_TRUE(Search::DFS(g, 3));
    EXPECT_TRUE(Search::DFS(g, 4));
    EXPECT_TRUE(Search::DFS(g, 5));
    EXPECT_TRUE(Search::DFS(g, 6));
    EXPECT_FALSE(Search::DFS(g, 7));
}

TEST(DFSTest, LargeGraph) {
    auto const file{get_graph_file("large")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    EXPECT_TRUE(Search::DFS(g, 1));
    EXPECT_TRUE(Search::DFS(g, 2));
    EXPECT_TRUE(Search::DFS(g, 3));
    EXPECT_TRUE(Search::DFS(g, 4));
    EXPECT_TRUE(Search::DFS(g, 5));
    EXPECT_TRUE(Search::DFS(g, 6));
    EXPECT_TRUE(Search::DFS(g, 7));
    EXPECT_TRUE(Search::DFS(g, 8));
    EXPECT_TRUE(Search::DFS(g, 9));
    EXPECT_FALSE(Search::DFS(g, 10));
}

TEST(DFSTest, CycleGraph) {
    auto const file{get_graph_file("cycle")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    EXPECT_TRUE(Search::DFS(g, 1));
    EXPECT_TRUE(Search::DFS(g, 2));
    EXPECT_TRUE(Search::DFS(g, 3));
    EXPECT_TRUE(Search::DFS(g, 4));
    EXPECT_TRUE(Search::DFS(g, 5));
    EXPECT_TRUE(Search::DFS(g, 6));
    EXPECT_FALSE(Search::DFS(g, 7));
}