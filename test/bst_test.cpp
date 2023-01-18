#include "binary_search_tree.h"
#include "gtest/gtest.h"

TEST(bst_tests, construction) {
    BinarySearchTree bst{1, 2, 5, 4, 3};
    EXPECT_TRUE(bst.root());
    EXPECT_EQ(bst.root().value(), 3);
    EXPECT_EQ(bst.size(), 3);

    BinarySearchTree bst2{1, 2};
    EXPECT_TRUE(bst2.root());
    EXPECT_EQ(bst2.root().value(), 1);
    EXPECT_EQ(bst2.size(), 2);

    BinarySearchTree bst3(3);
    EXPECT_TRUE(bst3.root());
    EXPECT_EQ(bst3.root().value(), 3);
    EXPECT_EQ(bst3.size(), 1);

    BinarySearchTree bst4;
    EXPECT_FALSE(bst4.root());
    EXPECT_EQ(bst4.size(), 0);
}

TEST(bst_tests, insert) {
    BinarySearchTree bst{1, 2, 3, 5, 6};
    bst.insert(4);
    EXPECT_EQ(bst.size(), 3);
    bst.insert(0);
    EXPECT_EQ(bst.size(), 3);
    bst.insert(7);
    EXPECT_EQ(bst.size(), 4);
}

TEST(bst_tests, delete_node) {
    BinarySearchTree bst{1, 2, 3, 4, 7, 5, 6, 8, 9, 10, 11};
    EXPECT_TRUE(bst.deleteNode(11));
    EXPECT_EQ(bst.size(), 4);
    EXPECT_TRUE(bst.deleteNode(8));
    EXPECT_TRUE(bst.deleteNode(3));
    EXPECT_TRUE(bst.deleteNode(7));
    EXPECT_TRUE(bst.deleteNode(2));
    EXPECT_EQ(bst.size(), 3);
    EXPECT_TRUE(bst.root());
    EXPECT_EQ(bst.root().value(), 5);
    EXPECT_TRUE(bst.deleteNode(5));
    EXPECT_TRUE(bst.root());
    EXPECT_EQ(bst.root().value(), 6);
}

TEST(bst_tests, find_less) {
    BinarySearchTree bst{1, 2, 4, 6, 8, 10, 11};
    EXPECT_TRUE(bst.findLess(11));
    EXPECT_EQ(bst.findLess(11), 10);
    EXPECT_TRUE(bst.findLess(10));
    EXPECT_EQ(bst.findLess(10), 8);
    EXPECT_TRUE(bst.findLess(6));
    EXPECT_EQ(bst.findLess(6), 4);
    EXPECT_TRUE(bst.findLess(2));
    EXPECT_EQ(bst.findLess(2), 1);
    EXPECT_FALSE(bst.findLess(1));
}

TEST(bst_tests, find_greater) {
    BinarySearchTree bst{1, 2, 4, 6, 8, 10, 11};
    EXPECT_TRUE(bst.findGreater(1));
    EXPECT_EQ(bst.findGreater(1), 2);
    EXPECT_TRUE(bst.findGreater(2));
    EXPECT_EQ(bst.findGreater(2), 4);
    EXPECT_TRUE(bst.findGreater(4));
    EXPECT_EQ(bst.findGreater(4), 6);
    EXPECT_TRUE(bst.findGreater(6));
    EXPECT_EQ(bst.findGreater(6), 8);
    EXPECT_TRUE(bst.findGreater(8));
    EXPECT_EQ(bst.findGreater(8), 10);
    EXPECT_TRUE(bst.findGreater(10));
    EXPECT_EQ(bst.findGreater(10), 11);
    EXPECT_FALSE(bst.findGreater(11));
    EXPECT_FALSE(bst.findGreater(12));
}

TEST(bst_tests, find_less_or_equal) {
    BinarySearchTree bst{1, 2, 4, 6, 8, 10, 11};
    EXPECT_EQ(bst.findLessOrEqual(1), 1);
    EXPECT_EQ(bst.findLessOrEqual(2), 2);
    EXPECT_EQ(bst.findLessOrEqual(4), 4);
    EXPECT_EQ(bst.findLessOrEqual(5), 4);
    EXPECT_EQ(bst.findLessOrEqual(6), 6);
    EXPECT_EQ(bst.findLessOrEqual(8), 8);
    EXPECT_EQ(bst.findLessOrEqual(10), 10);
    EXPECT_EQ(bst.findLessOrEqual(11), 11);
    EXPECT_FALSE(bst.findLessOrEqual(0));
}

TEST(bst_tests, find_greater_or_equal) {
    BinarySearchTree bst{1, 2, 4, 6, 8, 10, 11};
    EXPECT_EQ(bst.findGreaterOrEqual(1), 1);
    EXPECT_EQ(bst.findGreaterOrEqual(2), 2);
    EXPECT_EQ(bst.findGreaterOrEqual(4), 4);
    EXPECT_EQ(bst.findGreaterOrEqual(5), 6);
    EXPECT_EQ(bst.findGreaterOrEqual(6), 6);
    EXPECT_EQ(bst.findGreaterOrEqual(8), 8);
    EXPECT_EQ(bst.findGreaterOrEqual(10), 10);
    EXPECT_EQ(bst.findGreaterOrEqual(11), 11);
    EXPECT_FALSE(bst.findGreaterOrEqual(12));
}

TEST(bst_tests, find_in_range) {
    BinarySearchTree bst{1, 2, 4, 6, 8, 10, 11};
    EXPECT_FALSE(bst.findInRange(12, 15));
    auto const& range = bst.findInRange(1, 4);
    std::vector<int> ground_truth{1, 2, 4};
    EXPECT_TRUE(range);
    EXPECT_TRUE(range.value().size() == ground_truth.size());
    for (unsigned int i = 0; i < range.value().size(); ++i) {
        EXPECT_EQ(range.value()[i], ground_truth[i]);
    }
}