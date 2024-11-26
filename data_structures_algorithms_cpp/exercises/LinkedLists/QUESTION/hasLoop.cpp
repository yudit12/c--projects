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
        Node* tail;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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

        Node* getTail() {
            return tail; 
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
            tail = nullptr;
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Check if the linked list has a loop                |
        //   | - Return type: bool                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'slow' and 'fast'                |
        //   | - 'slow' moves one step, 'fast' moves two            |
        //   | - If they meet, a loop exists                        |
        //   | - Return true if loop found, false otherwise         |
        //   | - 'fast' checks for null and its 'next' for null     |
        //   +======================================================+

        // bool hasLoop(){
        //     Node * temp = head;
        //     int counter = length;
        //     while (temp->next && counter !=0){
        //         temp = temp->next;
        //     }

        //     if (temp->next == nullptr){
        //         return false;
        //     }
        //     else{
        //         return true;
        //     }
        // }
    bool hasLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // Moves 1 step
            fast = fast->next->next;   // Moves 2 steps

            if (slow == fast) {
                return true;  // Loop detected
            }
        }

        return false;  // No loop detected
    }


};
int main() {
    std::cout << "hasLoop.cpp" << std::endl;
    LinkedList * list = new LinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    list->append(6);
    list->printList();
    std::cout<<list->getLength()<<std::endl;
    std::cout<<list->hasLoop()<<std::endl;
  
    return 0;
}



