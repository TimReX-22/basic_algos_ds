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