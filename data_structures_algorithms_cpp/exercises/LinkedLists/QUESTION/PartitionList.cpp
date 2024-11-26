#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Partition list around value x                      |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create two dummy nodes for two new lists           |
        //   | - One list for nodes less than x                     |
        //   | - Another list for nodes greater or equal to x       |
        //   | - Loop through original list                         |
        //   | - Assign nodes to new lists based on value           |
        //   | - Merge the two new lists                            |
        //   | - Update the original list's head                    |
        //   +======================================================+

        void partitionList(int x) {
            if (!head || !head->next) return; // If the list has 0 or 1 node, no need to partition.

            Node* lessTail = nullptr;  // Tail pointer for "less than x" segment
            Node* greaterHead = nullptr;  // Head pointer for "greater or equal to x" segment
            Node* greaterTail = nullptr;  // Tail pointer for "greater or equal to x" segment
            Node* current = head;  // Pointer to traverse the list

            while (current) {
                Node* nextNode = current->next;  // Save the next node
                if (current->value < x) {
                    // Add to the "less than x" segment
                    if (!lessTail) {
                        head = current;  // Update the head of the "less than x" segment
                        lessTail = current;
                    } else {
                        lessTail->next = current;
                        lessTail = lessTail->next;
                    }
                } else {
                    // Add to the "greater or equal to x" segment
                    if (!greaterHead) {
                        greaterHead = current;
                        greaterTail = current;
                    } else {
                        greaterTail->next = current;
                        greaterTail = greaterTail->next;
                    }
                }
                current->next = nullptr;  // Disconnect the current node from the rest of the list
                current = nextNode;  // Move to the next node
            }

            // Merge the two segments
            if (lessTail) {
                lessTail->next = greaterHead;  // Connect the two segments
            } else {
                head = greaterHead;  // If there are no nodes < x, set head to the "greater" segment
            }
        }

};


int main() {
    std::cout << "partitionList" << std::endl;
    LinkedList * list = new LinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    // list->append(6);
    list->printList();
    
    return 0;
}