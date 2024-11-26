#include <iostream>
#include <unordered_set>

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
        //   | - Remove duplicate nodes from the list               |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'current' and 'runner'           |
        //   | - 'current' scans each node                          |
        //   | - 'runner' checks for duplicates ahead               |
        //   | - If duplicate found, delete it                      |
        //   | - Update 'next' pointers and reduce length           |
        //   | - No return value, list updated in-place             |
        //   +======================================================+
         // Remove duplicates from the linked list
        void removeDuplicates() {
            unordered_set<int> seen;  // This will store values we have already seen
            Node* current = head;
            Node* prev = nullptr;

            while (current != nullptr) {
                if (seen.find(current->value) != seen.end()) {
                    // Value is a duplicate, so remove it
                    prev->next = current->next;
                    delete current;
                    length--;  // Decrease length as a node is removed
                    current = prev->next;  // Move to the next node
                } else {
                    // Value is not a duplicate, add it to the set
                    seen.insert(current->value);
                    prev = current;
                    current = current->next;  // Move to the next node
                }
                
            }
        }
};

int main() {
    std::cout << "removeDuplicates" << std::endl;
    LinkedList * list = new LinkedList(1);
    list->append(2);
    list->append(3);
    list->append(2);
    list->append(4);
    list->append(5);
    list->append(3);
    // // list->append(6);
    list->removeDuplicates();
    // list->printList();
    
    return 0;
}
