#include <gtest/gtest.h>
#include "LinkedList.h"  // Include your LinkedList class

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList* list;

    void SetUp() override {
              
    }

    void TearDown() override {
        // Clean up the LinkedList
        delete list;
    }

    // Helper method to initialize the LinkedList
    void initializeListWithDefaultConstructor() {
        list = new LinkedList();
    }

    void initializeListWithParameterizedConstructor(int value) {
        list = new LinkedList(value);
    }
};

TEST_F(LinkedListTest, ParameterizedConstructorInitializesCorrectly) {
    
    initializeListWithParameterizedConstructor(10);
    ASSERT_NE(list->getHead(), nullptr);
    ASSERT_NE(list->getTail(), nullptr);
    EXPECT_EQ(list->getHead(), list->getTail());
    EXPECT_EQ(list->getHead()->value, 10);
    EXPECT_EQ(list->getHead()->next, nullptr);
    EXPECT_EQ(list->getLength(), 1);
}

TEST_F(LinkedListTest, DefaultConstructorInitializesCorrectly) {
    initializeListWithDefaultConstructor();
    EXPECT_EQ(list->getLength(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// TEST_F(LinkedListTest, TestInitialLength) {
//     EXPECT_EQ(list->getLength(), 0);
// }

// TEST_F(LinkedListTest, TestAppend) {
//     list->append(10);
//     EXPECT_EQ(list->getLength(), 1);
//     list->append(20);
//     EXPECT_EQ(list->getLength(), 2);
// }

// TEST_F(LinkedListTest, TestDeleteLast) {
//     list->append(10);
//     list->append(20);
//     list->deleteLast();
//     EXPECT_EQ(list->getLength(), 1);
//     list->deleteLast();
//     EXPECT_EQ(list->getLength(), 0);
// }

// TEST_F(LinkedListTest, TestGetHeadAndTail) {
//     list->append(10);
//     EXPECT_EQ(list->getHead(), 10);
//     list->append(20);
//     EXPECT_EQ(list->getTail(), 20);
// }