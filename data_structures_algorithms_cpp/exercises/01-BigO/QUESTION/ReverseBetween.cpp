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
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
    
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Reverse nodes between positions m and n            |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create a dummy node and set its next to head       |
        //   | - Use 'prev' pointer to go to m-th node              |
        //   | - Use 'current' pointer for m+1 to n nodes           |
        //   | - Loop to reverse m+1 to n nodes                     |
        //   | - Update original list's head                        |
        //   | - Free dummy node memory                             |
        //   +======================================================+

        // void reverseBetween(int m, int n){
        //     Node* temp = head;
        //     Node* startRange = nullptr;
        //     Node* prevStart = nullptr;
        //     Node* endRange = nullptr;
        //     int counter =0 ;
        //     //Assumption: You can assume that m and n are not out of bounds.
        //     while (counter <= n){
        //         if (counter == m-1){
        //             prevStart = temp;
        //         }
        //         if (counter == m){
        //             startRange = temp;
        //         }
        //         if (counter == n){
        //             endRange = temp;
        //         }
        //         temp = temp->next;
        //         counter++;
        //     }
        //     std::cout << "prev_start = " <<prevStart->value<< std::endl;
        //     std::cout << "start = " <<startRange->value<< std::endl;
        //     std::cout << "end = " <<endRange->value<< std::endl;

        //     temp = startRange;
        //     Node* prev = endRange->next;
        //     Node* after = endRange->next;
        //     while(temp<=endRange){
        //         after = temp->next;
        //         temp->next = prev;
        //         prev = temp;
        //         temp = after;
        //     }
        //     prevStart ->next =endRange;


        // }

        void reverseBetween(int m, int n) {
            if (m == n) return; // No need to reverse if m and n are the same

            Node* dummy = new Node(0); // Create a dummy node
            dummy->next = head;
            Node* prevStart = dummy;

            // Step 1: Traverse to the (m-1)-th node
            for (int i = 0; i < m; i++) {
                prevStart = prevStart->next;
            }

            // Step 2: Initialize pointers for the reversal
            Node* startRange = prevStart->next;  // Start of the range to reverse
            Node* current = startRange->next;   // Node to be moved
            Node* after = nullptr;

            // Step 3: Reverse the sublist from m to n
            for (int i = 0; i < n - m; i++) {
                after = current->next;          // Store next node
                current->next = prevStart->next; // Insert current node at the start of the sublist
                prevStart->next = current;      // Update the previous node's next
                startRange->next = after;       // Update the end of the reversed list
                current = after;                // Move to the next node
            }

            // Step 4: Update head if needed and clean up dummy node
            if (dummy->next != head) {
                head = dummy->next;
            }
            delete dummy;
        }


       
    
};

int main() {
    std::cout << "reverseBetween" << std::endl;
    LinkedList * list = new LinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    list->printList();
    list->reverseBetween(1,3);
    list->printList();
    
    return 0;
}


