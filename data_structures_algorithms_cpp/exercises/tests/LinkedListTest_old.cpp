#include <gtest/gtest.h>
#include "LinkedList.h"  // Include your LinkedList class

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList* list;

    void SetUp() override {
        list = new LinkedList();
    }

    void TearDown() override {
        delete list;
    }
};

TEST_F(LinkedListTest, TestInitialLength) {
    EXPECT_EQ(list->getLength(), 0);
}

TEST_F(LinkedListTest, TestAppend) {
    list->append(10);
    EXPECT_EQ(list->getLength(), 1);
    list->append(20);
    EXPECT_EQ(list->getLength(), 2);
}

TEST_F(LinkedListTest, TestDeleteLast) {
    list->append(10);
    list->append(20);
    list->deleteLast();
    EXPECT_EQ(list->getLength(), 1);
    list->deleteLast();
    EXPECT_EQ(list->getLength(), 0);
}

TEST_F(LinkedListTest, TestGetHeadAndTail) {
    list->append(10);
    EXPECT_EQ(list->getHead(), 10);
    list->append(20);
    EXPECT_EQ(list->getTail(), 20);
}