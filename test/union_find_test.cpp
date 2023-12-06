#include "union_find.h"

#include <gtest/gtest.h>

TEST(UnionFindTest, makeSet) {
    UnionFind u(3);
    u.makeSet(3);
    u.makeSet(4);

    EXPECT_TRUE(u.find(1) == u.find(1));
    EXPECT_TRUE(u.find(1) != u.find(2));
    EXPECT_TRUE(u.find(1) != u.find(3));
    EXPECT_TRUE(u.find(1) != u.find(4));
}

TEST(UnionFindTest, merge) {
    UnionFind u(4);
    u.merge(1, 2);
    u.merge(3, 4);

    EXPECT_TRUE(u.find(1) == u.find(2));
    EXPECT_TRUE(u.find(3) == u.find(4));
}