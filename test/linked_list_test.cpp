#include "linked_list.h"

#include "gtest/gtest.h"

TEST(linked_list_tests, access_operator) {
    LinkedList<int> ll{1, 2, 3};
    EXPECT_EQ(ll[0], 1);
    EXPECT_EQ(ll[1], 2);
    EXPECT_EQ(ll[2], 3);
    EXPECT_THROW(ll[3], std::invalid_argument);
    EXPECT_THROW(ll[-1], std::invalid_argument);
    LinkedList<int> ll2;
    EXPECT_THROW(ll2[0], std::invalid_argument);
}

TEST(linked_list_tests, at) {
    LinkedList<int> ll{1, 2, 3};
    EXPECT_EQ(ll.at(0), 1);
    EXPECT_EQ(ll.at(1), 2);
    EXPECT_EQ(ll.at(2), 3);
    EXPECT_THROW(ll.at(3), std::invalid_argument);
    EXPECT_THROW(ll.at(-1), std::invalid_argument);
}

TEST(linked_list_tests, size) {
    LinkedList<int> ll{1, 2, 3};
    EXPECT_EQ(ll.size(), 3);
    LinkedList<int> ll2;
    EXPECT_EQ(ll2.size(), 0);
    LinkedList<int> ll3(1);
    EXPECT_EQ(ll3.size(), 1);
}

TEST(linked_list_tests, empty) {
    LinkedList<int> ll;
    EXPECT_TRUE(ll.empty());
    ll.insert(1);
    EXPECT_FALSE(ll.empty());
}

TEST(linked_list_tests, front_back) {
    LinkedList<int> ll;
    EXPECT_FALSE(ll.front());
    ll.insert(1);
    EXPECT_EQ(ll.front(), 1);
    EXPECT_EQ(ll.back(), 1);
    ll.insert(2);
    EXPECT_EQ(ll.back(), 2);
}

TEST(linked_list_tests, insert) {
    LinkedList<int> ll;
    ll.insert(1);
    EXPECT_EQ(ll[0], 1);
    ll.insert(2);
    EXPECT_EQ(ll[0], 1);
    EXPECT_EQ(ll[1], 2);
    ll.insert(3);
    EXPECT_EQ(ll[0], 1);
    EXPECT_EQ(ll[1], 2);
    EXPECT_EQ(ll[2], 3);
}

TEST(linked_list_tests, insert_at) {
    LinkedList<int> ll{1, 2, 3};
    ll.insertAt(0, 5);
    EXPECT_EQ(ll[0], 5);
    EXPECT_EQ(ll[1], 1);
    EXPECT_EQ(ll[2], 2);
    EXPECT_EQ(ll[3], 3);
    ll.insertAt(3, 6);
    EXPECT_EQ(ll[0], 5);
    EXPECT_EQ(ll[1], 1);
    EXPECT_EQ(ll[2], 2);
    EXPECT_EQ(ll[3], 6);
    EXPECT_EQ(ll[4], 3);
    ll.insertAt(5, 7);
    EXPECT_EQ(ll[0], 5);
    EXPECT_EQ(ll[1], 1);
    EXPECT_EQ(ll[2], 2);
    EXPECT_EQ(ll[3], 6);
    EXPECT_EQ(ll[4], 3);
    EXPECT_THROW(ll.insertAt(7, 100), std::invalid_argument);
}

TEST(linked_list_tests, remove_by_key) {
    LinkedList<int> ll{1, 2, 3, 4, 5};
    ll.removeByKey(3);
    EXPECT_EQ(ll.size(), 4);
    EXPECT_EQ(ll.at(2), 4);
    ll.removeByKey(5);
    EXPECT_EQ(ll.size(), 3);
    EXPECT_EQ(ll.at(2), 4);
    EXPECT_EQ(ll.back(), 4);
    EXPECT_THROW(ll.removeByKey(10), std::invalid_argument);
}

TEST(linked_list_tests, remove_by_idx) {
    LinkedList<int> ll{1, 2, 3, 4, 5};
    ll.removeByIdx(2);
    EXPECT_EQ(ll.size(), 4);
    EXPECT_EQ(ll.at(2), 4);
    ll.removeByIdx(3);
    EXPECT_EQ(ll.size(), 3);
    EXPECT_EQ(ll.at(2), 4);
    EXPECT_EQ(ll.back(), 4);
    EXPECT_THROW(ll.removeByIdx(10), std::invalid_argument);
}

TEST(linked_list_tests, sort) {
    LinkedList<int> ll{5, 2, 4, 8, 1, 3};
    ll.sort();
    EXPECT_EQ(ll[0], 1);
    EXPECT_EQ(ll[1], 2);
    EXPECT_EQ(ll[2], 3);
    EXPECT_EQ(ll[3], 4);
    EXPECT_EQ(ll[4], 5);
    EXPECT_EQ(ll[5], 8);
    ll.sort(false);
    EXPECT_EQ(ll[0], 8);
    EXPECT_EQ(ll[1], 5);
    EXPECT_EQ(ll[2], 4);
    EXPECT_EQ(ll[3], 3);
    EXPECT_EQ(ll[4], 2);
    EXPECT_EQ(ll[5], 1);
}
