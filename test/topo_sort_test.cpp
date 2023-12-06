#include "topo_sort.h"

#include <gtest/gtest.h>

TEST(TopoSortTest, SmallGraph) {
    auto const file{get_graph_file("small")};
    ASSERT_TRUE(file);
    std::string const graph_file{*file};
    auto graph_json{Graph::createGraphFromJson(graph_file, true)};
    ASSERT_TRUE(graph_json);
    Graph g{*graph_json};

    auto const order = topoSort(g);
    ASSERT_TRUE(order.size() == 6);

    EXPECT_EQ(order[0], 1);
    EXPECT_EQ(order[1], 2);
    EXPECT_EQ(order[2], 3);
    EXPECT_EQ(order[3], 5);
    EXPECT_EQ(order[4], 4);
    EXPECT_EQ(order[5], 6);
}