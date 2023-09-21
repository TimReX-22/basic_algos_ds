#include "kd_tree.h"

#include "gtest/gtest.h"

TEST(KDTreeTest, DistanceFunction) {
    std::vector<int> point1 = {5, 3};
    std::vector<int> point2 = {7, 1};
    ASSERT_FLOAT_EQ(distance(point1, point2), 8);
}

TEST(KDTreeTest, InsertSinglePoint) {
    KDTree tree;
    std::vector<int> point = {5, 3};
    EXPECT_TRUE(tree.insert(point));
    ASSERT_TRUE(tree.contains(point));
}

TEST(KDTreeTest, InsertMultiplePoints) {
    KDTree tree;
    std::vector<int> point1 = {2, 3};
    std::vector<int> point2 = {7, 1};
    std::vector<int> point3 = {9, 6};
    EXPECT_TRUE(tree.insert(point3));
    EXPECT_TRUE(tree.insert(point2));
    EXPECT_TRUE(tree.insert(point1));
    ASSERT_TRUE(tree.contains(point1));
    ASSERT_TRUE(tree.contains(point2));
    ASSERT_TRUE(tree.contains(point3));
}

TEST(KDTreeTest, InsertDuplicatePoint) {
    KDTree tree;
    std::vector<int> point = {4, 5};
    EXPECT_TRUE(tree.insert(point));
    EXPECT_FALSE(tree.insert(point));
    ASSERT_TRUE(tree.contains(point));
}

TEST(KDTreeTest, InsertWrongSizePoint) {
    KDTree tree;
    std::vector<int> point1 = {4, 5};
    std::vector<int> point2 = {4, 5, 6};
    EXPECT_TRUE(tree.insert(point1));
    EXPECT_FALSE(tree.insert(point2));
    ASSERT_TRUE(tree.contains(point1));
    ASSERT_FALSE(tree.contains(point2));
}

TEST(KDTreeTest, InsertSingleNode) {
    KDTree tree;
    std::vector<int> point = {5, 3};
    tree.insert(point);

    auto const traversal = tree.inOrderTraversal();
    ASSERT_EQ(traversal.size(), 1);
    ASSERT_EQ(traversal[0], point);
}

TEST(KDTreeTest, InsertInCorrectOrder) {
    KDTree tree;
    tree.insert({5, 5});
    tree.insert({2, 4});
    tree.insert({8, 7});
    tree.insert({7, 6});
    tree.insert({9, 8});

    auto const traversal = tree.inOrderTraversal();

    std::vector<std::vector<int>> expected = {
        {2, 4}, {5, 5}, {7, 6}, {8, 7}, {9, 8}};

    ASSERT_EQ(traversal, expected);
}

TEST(KDTreeTest, NNBasicFunctionality) {
    KDTree tree;
    tree.insert({2, 3});
    tree.insert({5, 4});
    tree.insert({9, 6});
    tree.insert({4, 7});
    tree.insert({8, 1});

    auto nn = tree.nearestNeighbor({7, 2});
    ASSERT_TRUE(nn.has_value());
    EXPECT_EQ(nn.value(), std::vector<int>({8, 1}));
}

TEST(KDTreeTest, NNEmptyTree) {
    KDTree tree;
    auto nn = tree.nearestNeighbor({7, 2});
    EXPECT_FALSE(nn.has_value());
}

TEST(KDTreeTest, NNSingleNodeTree) {
    KDTree tree;
    tree.insert({3, 3});

    auto nn = tree.nearestNeighbor({7, 7});
    ASSERT_TRUE(nn.has_value());
    EXPECT_EQ(nn.value(), std::vector<int>({3, 3}));
}

TEST(KDTreeTest, NNEdgeCasesWithDimensions) {
    KDTree tree;
    tree.insert({0, 7});
    tree.insert({0, 8});
    tree.insert({0, 4});
    tree.insert({0, 9});

    auto nn = tree.nearestNeighbor({0, 5});
    ASSERT_TRUE(nn.has_value());
    EXPECT_EQ(nn.value(), std::vector<int>({0, 4}));
}

TEST(KDTreeTest, MultipleNodesSameDistance) {
    KDTree tree;
    tree.insert({1, 1});
    tree.insert({-1, -1});
    tree.insert({1, -1});
    tree.insert({-1, 1});

    auto nn = tree.nearestNeighbor({0, 0});
    ASSERT_TRUE(nn.has_value());

    EXPECT_TRUE(
        nn.value() == std::vector<int>({1, 1}) ||
        nn.value() == std::vector<int>({-1, -1}) ||
        nn.value() == std::vector<int>({1, -1}) ||
        nn.value() == std::vector<int>({-1, 1}));
}

TEST(KDTreeTest, HigherDimensions) {
    KDTree tree;
    tree.insert({2, 3, 4});
    tree.insert({5, 6, 7});
    tree.insert({8, 9, 10});

    auto nn = tree.nearestNeighbor({6, 7, 8});
    ASSERT_TRUE(nn.has_value());
    EXPECT_EQ(nn.value(), std::vector<int>({5, 6, 7}));
}
