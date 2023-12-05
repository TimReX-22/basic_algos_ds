#include "graph.h"

#include <gtest/gtest.h>

TEST(GraphTest, AddVertexTest) {
    Graph g;
    EXPECT_TRUE(g.addVertex(1));
    EXPECT_TRUE(g.addVertex(2));
    EXPECT_TRUE(g.containsVertex(1));
    EXPECT_TRUE(g.containsVertex(2));
    EXPECT_FALSE(g.addVertex(1));
}

TEST(GraphTest, AddEdgeTest) {
    Graph g;
    EXPECT_TRUE(g.addVertex(1));
    EXPECT_TRUE(g.addVertex(2));
    EXPECT_TRUE(g.addVertex(3));
    EXPECT_TRUE(g.addEdge(1, 2, 1.0));
    EXPECT_TRUE(g.addEdge(2, 3, 2.0));
    EXPECT_FALSE(g.addEdge(1, 4, 1.0));
    EXPECT_FALSE(g.addEdge(1, 1, 1.0));

    EXPECT_FLOAT_EQ(*g.weight(1, 2), 1.0);
    EXPECT_FLOAT_EQ(*g.weight(2, 3), 2.0);
}

TEST(GraphTest, ContainsVertexTest) {
    Graph g;
    g.addVertex(1);
    EXPECT_TRUE(g.containsVertex(1));
    EXPECT_FALSE(g.containsVertex(2));
}

TEST(GraphTest, NeighborsTest) {
    Graph g(false);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addEdge(1, 2, 1.0);
    g.addEdge(1, 3, 1.0);

    auto neighbors = g.neighbors(1);
    ASSERT_TRUE(neighbors.has_value());
    EXPECT_EQ(neighbors->size(), 2);

    EXPECT_EQ(neighbors->at(0).first, 2);
    EXPECT_EQ(neighbors->at(1).first, 3);
}

TEST(GraphTest, WeightTest) {
    Graph g;
    g.addVertex(1);
    g.addVertex(2);
    g.addEdge(1, 2, 1.5);

    auto weight = g.weight(1, 2);
    ASSERT_TRUE(weight.has_value());
    EXPECT_DOUBLE_EQ(weight.value(), 1.5);

    auto invalid_weight = g.weight(1, 3);
    EXPECT_FALSE(invalid_weight.has_value());
}

TEST(GraphTest, WeightTestSparseValues) {
    Graph g;
    g.addVertex(10);
    g.addVertex(200);
    g.addEdge(10, 200, 1.5);

    auto const weight = g.weight(10, 200);
    ASSERT_TRUE(weight.has_value());
    EXPECT_DOUBLE_EQ(weight.value(), 1.5);

    auto invalid_weight = g.weight(1, 3);
    EXPECT_FALSE(invalid_weight.has_value());
}

TEST(GraphTest, GetVertices) {
    Graph g;
    g.addVertex(1);
    g.addVertex(10);
    g.addVertex(100);

    auto const vertices = g.vertices();
    ASSERT_EQ(vertices.size(), 3);
    EXPECT_EQ(vertices[0], 1);
    EXPECT_EQ(vertices[1], 10);
    EXPECT_EQ(vertices[2], 100);
}

TEST(GraphTest, GraphFromJsonTest) {
    std::string graph_file{"test/resources/graph_small.json"};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};
    ASSERT_EQ(g.size(), 6);

    auto neighbors_1{*g.neighbors(1)};
    ASSERT_EQ(neighbors_1.size(), 2);
    EXPECT_EQ(neighbors_1[0].first, 2);
    EXPECT_EQ(neighbors_1[1].first, 3);

    auto neighbors_2{*g.neighbors(2)};
    ASSERT_EQ(neighbors_2.size(), 2);
    EXPECT_EQ(neighbors_2[0].first, 3);
    EXPECT_EQ(neighbors_2[1].first, 4);
}