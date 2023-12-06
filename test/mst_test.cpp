#include <gtest/gtest.h>

#include "minimum_spanning_tree.h"

TEST(KruskalTest, SmallGraph) {
    auto const file{get_graph_file("small")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    auto const MST = Kruskal(g);
    for (auto m : MST) {
        std::cout << m.first << " -> " << m.second << "\n";
    }
    ASSERT_EQ(MST.size(), 5);
    EXPECT_EQ(MST[0].first, 2);
    EXPECT_EQ(MST[0].second, 3);
    EXPECT_EQ(MST[1].first, 4);
    EXPECT_EQ(MST[1].second, 6);
    EXPECT_EQ(MST[2].first, 1);
    EXPECT_EQ(MST[2].second, 2);
    EXPECT_EQ(MST[3].first, 5);
    EXPECT_EQ(MST[3].second, 4);
    EXPECT_EQ(MST[4].first, 3);
    EXPECT_EQ(MST[4].second, 5);
}