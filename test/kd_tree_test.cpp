#include "kd_tree.h"

#include "gtest/gtest.h"

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

    auto const traversal = tree.in_order_traversal();
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

    auto const traversal = tree.in_order_traversal();

    std::vector<std::vector<int>> expected = {
        {2, 4}, {5, 5}, {7, 6}, {8, 7}, {9, 8}};

    ASSERT_EQ(traversal, expected);
}
