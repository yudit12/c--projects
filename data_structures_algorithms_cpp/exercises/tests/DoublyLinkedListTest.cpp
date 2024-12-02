#include <gtest/gtest.h>
#include "DoublyLinkedList.h"  // Include your LinkedList class

class DoublyLinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedList* myDLL;

    void SetUp() override {
        myDLL = new DoublyLinkedList(); 
    }

    void TearDown() override {
        // Clean up the LinkedList
        delete myDLL;
    }

    // Helper method to initialize the LinkedList
    void initializeListWithDefaultConstructor() {
        delete myDLL;  // Free previously allocated memory
        myDLL = new DoublyLinkedList();
    }

    void initializeListWithParameterizedConstructor(int value) {
        delete myDLL;  // Free previously allocated memory
        myDLL = new DoublyLinkedList(value);
    }
};

TEST_F(DoublyLinkedListTest, ParameterizedConstructorInitializesCorrectly) {
    
    // initializeListWithParameterizedConstructor(10);
    myDLL = new DoublyLinkedList(7);

    // ASSERT_NE(list->getHead(), nullptr);
    // ASSERT_NE(list->getTail(), nullptr);
    // EXPECT_EQ(list->getHead(), list->getTail());
    // EXPECT_EQ(list->getHead()->value, 10);
    // EXPECT_EQ(list->getHead()->next, nullptr);
    // EXPECT_EQ(list->getLength(), 1);
}

TEST_F(DoublyLinkedListTest, DefaultConstructorInitializesCorrectly) {
    initializeListWithDefaultConstructor();
    // EXPECT_EQ(list->getLength(), 0);
    // EXPECT_EQ(list->getHead(), nullptr);
    // EXPECT_EQ(list->getTail(), nullptr);
}

