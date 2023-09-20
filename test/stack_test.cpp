#include "stack.h"

#include "gtest/gtest.h"

TEST(stack_test, insert_and_pop) {
    Stack<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    EXPECT_EQ(s.pop(), 4);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
    EXPECT_FALSE(s.pop());
}