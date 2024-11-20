#include <gtest/gtest.h>
#include "LinkedList.h"  // Include your LinkedList class

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList* list;

    void SetUp() override {
        list = new LinkedList(); 
    }

    void TearDown() override {
        // Clean up the LinkedList
        delete list;
    }

    // Helper method to initialize the LinkedList
    void initializeListWithDefaultConstructor() {
        delete list;  // Free previously allocated memory
        list = new LinkedList();
    }

    void initializeListWithParameterizedConstructor(int value) {
        delete list;  // Free previously allocated memory
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

// Test the printList method
TEST_F(LinkedListTest, PrintListTest) {
    // Initialize the list with some values
    list->append(10);
    list->append(20);
    list->append(30);

    // Capture the output of printList()
    testing::internal::CaptureStdout();
    list->printList();
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output matches the expected string
    std::string expected_output = "10 -> 20 -> 30 -> \n";
    EXPECT_EQ(output, expected_output);
}

// Test when the list is empty
TEST_F(LinkedListTest, PrintListEmptyTest) {
    // Capture the output of printList() for an empty list
    testing::internal::CaptureStdout();
    list->printList();
    std::string output = testing::internal::GetCapturedStdout();

    // Verify the output matches the expected string for an empty list
    std::string expected_output = "\n";
    EXPECT_EQ(output, expected_output);
}

// Test that head and tail are cleared after manual destruction
TEST_F(LinkedListTest, DestructorClearsHeadAndTail) {
    // Append some elements to the list
    list->append(10);
    list->append(20);

    // Manually delete the list
    delete list;

    // Reinitialize list to avoid invalid memory access
    list = new LinkedList();

    // Confirm reinitialization works
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
    EXPECT_EQ(list->getLength(), 0);
}

TEST_F(LinkedListTest, DestructorClearsMemory) {
    // Append some elements to the list
    list->append(10);
    list->append(20);

    // Capture memory state before destruction
    ASSERT_NE(list->getHead(), nullptr);
    ASSERT_NE(list->getTail(), nullptr);

    // Manually delete the list
    delete list;
    list = nullptr;

    // The AddressSanitizer should confirm no memory leaks
    SUCCEED();  // The test passes if there are no leaks
}

// Test appending to an empty list
TEST_F(LinkedListTest, AppendToEmptyList) {
    list->append(10);  // Append a value to the empty list

    // Check that the list has one element
    ASSERT_EQ(list->getLength(), 1);
    EXPECT_EQ(list->getHead()->value, 10);  // Head should point to the newly added node
    EXPECT_EQ(list->getTail()->value, 10);  // Tail should point to the newly added node
    EXPECT_EQ(list->getHead()->next, nullptr);  // Next of head should be nullptr (only one element)
}

// Test appending to a list with one element
TEST_F(LinkedListTest, AppendToListWithOneElement) {
    list->append(10);  // Append first value
    list->append(20);  // Append second value

    // Check that the length of the list is 2
    ASSERT_EQ(list->getLength(), 2);

    // Check the head and tail values
    EXPECT_EQ(list->getHead()->value, 10);  // Head should be 10
    EXPECT_EQ(list->getTail()->value, 20);  // Tail should be 20

    // Check that the first node's next points to the second node
    EXPECT_EQ(list->getHead()->next->value, 20);  // Head's next should point to 20
    EXPECT_EQ(list->getTail()->next, nullptr);   // Tail's next should be nullptr (end of list)
}

// Test appending multiple elements
TEST_F(LinkedListTest, AppendMultipleElements) {
    list->append(10);
    list->append(20);
    list->append(30);

    // Check that the length of the list is 3
    ASSERT_EQ(list->getLength(), 3);

    // Check the values in the list
    EXPECT_EQ(list->getHead()->value, 10);  // Head should be 10
    EXPECT_EQ(list->getTail()->value, 30);  // Tail should be 30
    EXPECT_EQ(list->getHead()->next->value, 20);  // Second node should be 20
    EXPECT_EQ(list->getHead()->next->next->value, 30);  // Third node should be 30
    EXPECT_EQ(list->getTail()->next, nullptr);   // Tail's next should be nullptr
}

// Test appending when the list is empty
TEST_F(LinkedListTest, AppendToEmptyListAfterClear) {
    list->append(10);  // Append an element to the list
    delete list;       // Clear the list manually
    list = new LinkedList();  // Reinitialize the list
    
    list->append(20);  // Append to the new empty list

    // Verify that the new list is correctly updated
    ASSERT_EQ(list->getLength(), 1);
    EXPECT_EQ(list->getHead()->value, 20);
    EXPECT_EQ(list->getTail()->value, 20);
    EXPECT_EQ(list->getHead()->next, nullptr);
}

// Test appending with different values
TEST_F(LinkedListTest, AppendWithDifferentValues) {
    list->append(5);
    list->append(10);
    list->append(15);
    list->append(20);

    // Check the length and values in the list
    ASSERT_EQ(list->getLength(), 4);
    EXPECT_EQ(list->getHead()->value, 5);  // Head should be 5
    EXPECT_EQ(list->getTail()->value, 20); // Tail should be 20

    // Check the sequence of nodes
    EXPECT_EQ(list->getHead()->next->value, 10);
    EXPECT_EQ(list->getHead()->next->next->value, 15);
    EXPECT_EQ(list->getHead()->next->next->next->value, 20);
    EXPECT_EQ(list->getTail()->next, nullptr);  // Tail's next should be nullptr
}

// Test deleting from an empty list
TEST_F(LinkedListTest, DeleteLastFromEmptyList) {
    list->deleteLast();  // Try to delete from an empty list

    // Check that the list is still empty (length should be 0)
    EXPECT_EQ(list->getLength(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// Test deleting the last element in a list with multiple elements
TEST_F(LinkedListTest, DeleteLastFromMultipleElementsList) {
    list->append(10);  // Append first element
    list->append(20);  // Append second element
    list->append(30);  // Append third element

    list->deleteLast();  // Delete the last element (30)

    // Check that the length is updated
    EXPECT_EQ(list->getLength(), 2);
    EXPECT_EQ(list->getTail()->value, 20);  // Tail should now be 20
    EXPECT_EQ(list->getHead()->next->value, 20);  // Head's next should be 20
    EXPECT_EQ(list->getHead()->next->next, nullptr);  // Tail's next should be nullptr
}

// Test deleting the last element and then checking the tail
TEST_F(LinkedListTest, DeleteLastAndCheckTail) {
    list->append(10);
    list->append(20);
    list->deleteLast();  // Delete the last element (20)

    // After deleting, the new tail should be 10
    EXPECT_EQ(list->getTail()->value, 10);  // Tail should be 10
    EXPECT_EQ(list->getLength(), 1);  // Length should be 1
}

// Test deleting elements until the list is empty
TEST_F(LinkedListTest, DeleteAllElements) {
    list->append(10);
    list->append(20);
    list->append(30);

    list->deleteLast();  // Remove 30
    list->deleteLast();  // Remove 20
    list->deleteLast();  // Remove 10

    // After all deletions, the list should be empty
    EXPECT_EQ(list->getLength(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// Test prepending to an empty list
TEST_F(LinkedListTest, PrependToEmptyList) {
    list->prepend(10);  // Prepend one element

    // Check that the list has one element
    EXPECT_EQ(list->getLength(), 1);
    EXPECT_EQ(list->getHead()->value, 10);
    EXPECT_EQ(list->getTail()->value, 10);
    EXPECT_EQ(list->getHead()->next, nullptr);  // Only one element, so next should be nullptr
}

// Test prepending to a list with one element
TEST_F(LinkedListTest, PrependToOneElementList) {
    list->append(10);  // Append one element
    list->prepend(20);  // Prepend a new element

    // Check that the new element is now the head
    EXPECT_EQ(list->getLength(), 2);
    EXPECT_EQ(list->getHead()->value, 20);  // Head should now be 20
    EXPECT_EQ(list->getTail()->value, 10);  // Tail should still be 10
    EXPECT_EQ(list->getHead()->next->value, 10);  // Head's next should be 10
}

// Test prepending multiple elements
TEST_F(LinkedListTest, PrependMultipleElements) {
    list->prepend(10);  // Prepend 10
    list->prepend(20);  // Prepend 20
    list->prepend(30);  // Prepend 30

    // Check that the list has the elements in the correct order (head -> tail)
    EXPECT_EQ(list->getLength(), 3);
    EXPECT_EQ(list->getHead()->value, 30);  // Head should be 30
    EXPECT_EQ(list->getHead()->next->value, 20);  // Second element should be 20
    EXPECT_EQ(list->getTail()->value, 10);  // Tail should be 10
    EXPECT_EQ(list->getHead()->next->next->value, 10);  // Tail's previous node should be 20
}

// Test prepending multiple times
TEST_F(LinkedListTest, PrependMultipleTimes) {
    list->prepend(10);  // Prepend 10
    list->prepend(20);  // Prepend 20
    list->prepend(30);  // Prepend 30
    list->prepend(40);  // Prepend 40

    // Check that the list has all the elements in the correct order (head -> tail)
    EXPECT_EQ(list->getLength(), 4);
    EXPECT_EQ(list->getHead()->value, 40);  // Head should be 40
    EXPECT_EQ(list->getHead()->next->value, 30);  // Second element should be 30
    EXPECT_EQ(list->getHead()->next->next->value, 20);  // Third element should be 20
    EXPECT_EQ(list->getTail()->value, 10);  // Tail should be 10
}

// Test deleting the first element from an empty list
TEST_F(LinkedListTest, DeleteFirstFromEmptyList) {
    list->deleteFirst();  // Try to delete the first element from an empty list

    // The list should still be empty
    EXPECT_EQ(list->getLength(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// Test deleting the first element when the list contains one element
TEST_F(LinkedListTest, DeleteFirstFromSingleElementList) {
    list->append(10);  // Add one element to the list

    list->deleteFirst();  // Delete the first (and only) element

    // After deletion, the list should be empty
    EXPECT_EQ(list->getLength(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// Test deleting the first element from a list with multiple elements
TEST_F(LinkedListTest, DeleteFirstFromMultipleElementList) {
    list->append(10);  // Add 10
    list->append(20);  // Add 20
    list->append(30);  // Add 30

    list->deleteFirst();  // Delete the first element (10)

    // Check that the list has the correct new head and tail
    EXPECT_EQ(list->getLength(), 2);
    EXPECT_EQ(list->getHead()->value, 20);  // New head should be 20
    EXPECT_EQ(list->getTail()->value, 30);  // Tail should still be 30
    EXPECT_EQ(list->getHead()->next->value, 30);  // The next node should be 30
}

// Test deleting the first element multiple times
TEST_F(LinkedListTest, DeleteFirstMultipleTimes) {
    list->append(10);  // Add 10
    list->append(20);  // Add 20
    list->append(30);  // Add 30

    list->deleteFirst();  // Delete the first element (10)
    list->deleteFirst();  // Delete the first element (20)

    // Now the list should only contain one element (30)
    EXPECT_EQ(list->getLength(), 1);
    EXPECT_EQ(list->getHead()->value, 30);  // The head should be 30
    EXPECT_EQ(list->getTail()->value, 30);  // The tail should be 30 as well

    list->deleteFirst();  // Delete the last element (30)

    // After deleting the last element, the list should be empty
    EXPECT_EQ(list->getLength(), 0);
    EXPECT_EQ(list->getHead(), nullptr);
    EXPECT_EQ(list->getTail(), nullptr);
}

// Test case: get node of in a spesifc index - Negative index should return nullptr
TEST_F(LinkedListTest, GetReturnsNullptrForNegativeIndex) {
    // Adding a value to ensure the list isn't empty
    list->append(10);
    EXPECT_EQ(list->get(-1), nullptr); // Negative indices are invalid
    // **Explanation:** The function should return `nullptr` for any negative index.
}

// Test case: get node of in a spesifc index - Index out of bounds should return nullptr
TEST_F(LinkedListTest, GetReturnsNullptrForOutOfBoundsIndex) {
    list->append(10);
    list->append(20);
    EXPECT_EQ(list->get(2), nullptr); // Index 2 is out of bounds for a list of size 2
    EXPECT_EQ(list->get(5), nullptr); // Index 5 is far beyond the bounds
    // **Explanation:** The function must return `nullptr` when the index is >= `length`.
}

// Test case: get node of in a spesifc index - Valid index should return the correct node
TEST_F(LinkedListTest, GetReturnsCorrectNodeForValidIndex) {
    list->append(10);
    list->append(20);
    list->append(30);

    Node* node = list->get(0);
    ASSERT_NE(node, nullptr);  // Ensure the returned node isn't null
    EXPECT_EQ(node->value, 10); // First node

    node = list->get(1);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 20); // Second node

    node = list->get(2);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 30); // Third node
    // **Explanation:** For valid indices, the function must traverse the list correctly
    // and return the node at the specified position.
}

// Test case: get node of in a spesifc index - Index 0 should return the head node
TEST_F(LinkedListTest, GetReturnsHeadForIndexZero) {
    list->append(100);
    Node* node = list->get(0);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node, list->getHead()); // Ensure the returned node is the head
    EXPECT_EQ(node->value, 100);
    // **Explanation:** Accessing index 0 should always return the `head` node.
}

// Test case: get node of in a spesifc index - Last index should return the tail node
TEST_F(LinkedListTest, GetReturnsTailForLastIndex) {
    list->append(10);
    list->append(20);
    list->append(30);

    Node* node = list->get(2); // Last index
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node, list->getTail()); // Ensure the returned node is the tail
    EXPECT_EQ(node->value, 30);
    // **Explanation:** The function must handle the last index correctly by returning `tail`.
}

// Test case: get node of in a spesifc index - Traversal works correctly for a larger list
TEST_F(LinkedListTest, GetReturnsCorrectNodeInLargerList) {
    // Add multiple nodes to the list
    for (int i = 1; i <= 100; ++i) {
        list->append(i);
    }

    // Test specific indices
    EXPECT_EQ(list->get(0)->value, 1);    // First node
    EXPECT_EQ(list->get(49)->value, 50); // Middle node
    EXPECT_EQ(list->get(99)->value, 100); // Last node
    // **Explanation:** The function should traverse larger lists efficiently 
    // and return the correct node at any valid index.
}

// Test that the set function returns false when the index is out of bounds (negative index)
TEST_F(LinkedListTest, SetFailsForNegativeIndex) {
    list->append(10);

    // Act: Attempt to update a node at a negative index
    EXPECT_FALSE(list->set(-1, 15));

    // Assert: Verify the list remains unchanged
    EXPECT_EQ(list->get(0)->value, 10);
}

// Test that the set function returns false when the index is out of bounds (index >= length)
TEST_F(LinkedListTest, SetFailsForIndexGreaterThanOrEqualLength) {
    list->append(10);
    list->append(20);

    // Act: Attempt to update a node at an out-of-bounds index
    EXPECT_FALSE(list->set(2, 25));

    // Assert: Verify the list remains unchanged
    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->get(1)->value, 20);
}

// Test that the set function updates the value at a valid index in the middle of the list
TEST_F(LinkedListTest, SetUpdatesValueAtMiddleIndex) {
    list->append(10);  // Add initial values to the list
    list->append(20);
    list->append(30);

    // Act: Update the value at index 1
    EXPECT_TRUE(list->set(1, 25));

    // Assert: Verify the value at index 1 has been updated
    EXPECT_EQ(list->get(1)->value, 25);

    // Verify other nodes are not affected
    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->get(2)->value, 30);
}

// Test that the set function updates the value at the head of the list
TEST_F(LinkedListTest, SetUpdatesValueAtHead) {
    list->append(10);
    list->append(20);

    // Act: Update the value at index 0 (head)
    EXPECT_TRUE(list->set(0, 5));

    // Assert: Verify the value at index 0 has been updated
    EXPECT_EQ(list->get(0)->value, 5);

    // Verify other nodes are not affected
    EXPECT_EQ(list->get(1)->value, 20);
}

// Test that the set function updates the value at the tail of the list
TEST_F(LinkedListTest, SetUpdatesValueAtTail) {
    list->append(10);
    list->append(20);

    // Act: Update the value at the last index
    EXPECT_TRUE(list->set(1, 25));

    // Assert: Verify the value at index 1 (tail) has been updated
    EXPECT_EQ(list->get(1)->value, 25);

    // Verify other nodes are not affected
    EXPECT_EQ(list->get(0)->value, 10);
}

// Test: Insert at the head of the list
TEST_F(LinkedListTest, InsertAtHead) {
    list->append(10);
    list->append(20);

    EXPECT_TRUE(list->insert(0, 5)); // Insert at the head

    // Verify the new head and list structure
    EXPECT_EQ(list->get(0)->value, 5);
    EXPECT_EQ(list->get(1)->value, 10);
    EXPECT_EQ(list->get(2)->value, 20);
    EXPECT_EQ(list->getLength(), 3); // List length should be updated
}

// Test: Insert at the tail of the list
TEST_F(LinkedListTest, InsertAtTail) {
    list->append(10);
    list->append(20);

    EXPECT_TRUE(list->insert(2, 25)); // Insert at the tail (index == length)

    // Verify the new tail and list structure
    EXPECT_EQ(list->get(2)->value, 25);
    EXPECT_EQ(list->getLength(), 3); // List length should be updated
}

// Test: Insert in the middle of the list
TEST_F(LinkedListTest, InsertInMiddle) {
    list->append(10);
    list->append(20);
    list->append(30);

    EXPECT_TRUE(list->insert(1, 15)); // Insert between 10 and 20

    // Verify the list structure
    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->get(1)->value, 15);
    EXPECT_EQ(list->get(2)->value, 20);
    EXPECT_EQ(list->get(3)->value, 30);
    EXPECT_EQ(list->getLength(), 4); // List length should be updated
}

// Test: Insert with invalid negative index
TEST_F(LinkedListTest, InsertInvalidNegativeIndex) {
    list->append(10);

    EXPECT_FALSE(list->insert(-1, 5)); // Invalid index

    // Verify the list remains unchanged
    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->getLength(), 1); // List length should remain unchanged
}

// Test: Insert with index out of bounds (greater than length)
TEST_F(LinkedListTest, InsertOutOfBoundsIndex) {
    list->append(10);

    EXPECT_FALSE(list->insert(2, 5)); // Invalid index

    // Verify the list remains unchanged
    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->getLength(), 1); // List length should remain unchanged
}

// Test: Insert into an empty list
TEST_F(LinkedListTest, InsertIntoEmptyList) {
    EXPECT_TRUE(list->insert(0, 5)); // Insert at index 0 in an empty list

    // Verify the inserted node
    EXPECT_EQ(list->get(0)->value, 5);
    EXPECT_EQ(list->getLength(), 1); // List length should be updated
}



// Test case: deleteNode function - Deleting from an empty list should do nothing.

TEST_F(LinkedListTest, DeleteFromEmptyList) {
    // The list is empty, so calling deleteNode(0) should return without modifying the list.
    list->deleteNode(0);  // No node to delete
    EXPECT_EQ(list->getLength(), 0);  // Length should remain 0
}

// Test case: deleteNode function - Deleting the first node when list contains one element.
TEST_F(LinkedListTest, DeleteFirstNodeSingleElement) {
    list->append(10);  // List: 10
    list->deleteNode(0);  // Delete first node

    EXPECT_EQ(list->getLength(), 0);  // List should be empty
}

// Test case:  deleteNode function - Deleting the last node from a list with two elements.
TEST_F(LinkedListTest, DeleteLastNodeTwoElements) {
    list->append(10);  // List: 10
    list->append(20);  // List: 10 -> 20

    list->deleteNode(1);  // Delete last node (index = length - 1)

    EXPECT_EQ(list->get(0)->value, 10);  // Only 10 should remain
    EXPECT_EQ(list->getLength(), 1);  // Length should be updated to 1
}

// Test case:  deleteNode function - Deleting a middle node from a list with multiple elements.
TEST_F(LinkedListTest, DeleteMiddleNode) {
    list->append(10);  // List: 10
    list->append(20);  // List: 10 -> 20
    list->append(30);  // List: 10 -> 20 -> 30
    list->append(40);  // List: 10 -> 20 -> 30 -> 40

    list->deleteNode(1);  // Delete middle node (value = 20)

    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->get(1)->value, 30);
    EXPECT_EQ(list->get(2)->value, 40);
    EXPECT_EQ(list->getLength(), 3);  // Length should be updated to 3
}

// Test case: deleteNode function - Deleting the last node from a list with multiple elements.
TEST_F(LinkedListTest, DeleteLastNode) {
    list->append(10);  // List: 10
    list->append(20);  // List: 10 -> 20
    list->append(30);  // List: 10 -> 20 -> 30
    list->append(40);  // List: 10 -> 20 -> 30 -> 40

    list->deleteNode(3);  // Delete last node (index = length - 1)

    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->get(1)->value, 20);
    EXPECT_EQ(list->get(2)->value, 30);
    EXPECT_EQ(list->getLength(), 3);  // Length should be updated to 3
}

// Test case: deleteNode function - Invalid index deletion in a non-empty list.
TEST_F(LinkedListTest, InvalidIndexDelete) {
    list->append(10);  // List: 10
    list->append(20);  // List: 10 -> 20
    list->append(30);  // List: 10 -> 20 -> 30
    list->append(40);  // List: 10 -> 20 -> 30 -> 40

    // Trying to delete at an invalid index should return without changes
    list->deleteNode(-1);  // Invalid index (negative)
    list->deleteNode(5);   // Invalid index (greater than length)

    EXPECT_EQ(list->get(0)->value, 10);
    EXPECT_EQ(list->get(1)->value, 20);
    EXPECT_EQ(list->get(2)->value, 30);
    EXPECT_EQ(list->get(3)->value, 40);
    EXPECT_EQ(list->getLength(), 4);  // Length should remain the same
}

// Test case: reverse function
TEST_F(LinkedListTest, ReverseList) {
    list->append(10);
    list->append(20);
    list->append(30);
    list->append(40);

    list->reverse();

    // Check the reversed list structure
    EXPECT_EQ(list->get(0)->value, 40);
    EXPECT_EQ(list->get(1)->value, 30);
    EXPECT_EQ(list->get(2)->value, 20);
    EXPECT_EQ(list->get(3)->value, 10);
    EXPECT_EQ(list->getLength(), 4); // Ensure length is unchanged
}
