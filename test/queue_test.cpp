#include "queue.h"

#include "gtest/gtest.h"

TEST(queue_tests, enqueue) {
    Queue<int> q;
    ASSERT_TRUE(q.empty());
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    ASSERT_TRUE(q.size() == 3);
}

TEST(queue_tests, dequeue) {
    Queue<float> q{1.f, 2.f, 3.f};
    ASSERT_TRUE(q.size() == 3);

    auto const& last1 = q.dequeue();
    ASSERT_TRUE(last1);
    ASSERT_FLOAT_EQ(*last1, 3.f);
    ASSERT_TRUE(q.size() == 2);

    auto const& last2 = q.dequeue();
    ASSERT_TRUE(last2);
    ASSERT_FLOAT_EQ(*last2, 2.f);
    ASSERT_TRUE(q.size() == 1);

    auto const& last3 = q.dequeue();
    ASSERT_TRUE(last3);
    ASSERT_FLOAT_EQ(*last3, 1.f);
    ASSERT_TRUE(q.size() == 0);

    auto const& last_null = q.dequeue();
    ASSERT_FALSE(last_null);
}