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
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
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
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Find the middle node of the linked list            |
        //   | - Return type: Node*                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'slow' and 'fast'                |
        //   | - 'slow' moves one step, 'fast' moves two            |
        //   | - When 'fast' reaches the end, 'slow' is at middle   |
        //   | - Return 'slow' as the middle node                   |
        //   +======================================================+

        // // o(n)
        // // Node* findMiddleNode(){
        // //      // Check for an empty list
        // //     if (head == nullptr) {
        // //         return nullptr;
        // //     }
        // //     Node * one_step = head;
        // //     Node* tow_steps = head;
        // //     while (tow_steps->next){
        // //         one_step = one_step->next;
        // //         tow_steps = tow_steps->next;

        // //         if (tow_steps->next== nullptr){
        // //             return one_step;
        // //         }
        // //         else{
        // //             tow_steps = tow_steps->next;
        // //         }  
        // //     }
            
        // //     return one_step;
        // // }
        // // beter option - o(n)
         Node* findMiddleNode(){
             // Check for an empty list
            if (head == nullptr) {
                return nullptr;
            }
            Node * one_step = head;
            Node* tow_steps = head;
            while (tow_steps  && tow_steps->next ){
                one_step = one_step->next;
                tow_steps = tow_steps->next->next;
            }
            
            return one_step;
        }

};

int main() {
    std::cout << "findMiddleNode" << std::endl;
    LinkedList * list = new LinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    list->append(6);
    list->printList();
    Node* mid = list->findMiddleNode();
    std::cout<< mid->value<<endl;
    return 0;
}


