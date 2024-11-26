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
        //   | - Find the k-th node from the end of the list        |
        //   | - Return type: Node*                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use two pointers: 'slow' and 'fast'                |
        //   | - Move 'fast' k nodes ahead first                    |
        //   | - If 'fast' reaches null, k is too large             |
        //   | - Then move both 'slow' and 'fast' until end         |
        //   | - Return 'slow' as the k-th node from the end        |
        //   +======================================================+

        Node* findKthFromEnd(int k) {
            if (k <= 0) {
                return nullptr; // Handle invalid input
            }

            Node* fast = head;
            Node* slow = head;

            // Move the fast pointer k steps ahead
            for (int i = 0; i < k; ++i) {
                if (!fast) {
                    return nullptr; // If k is greater than the length of the list
                }
                fast = fast->next;
            }

            // Move both pointers until fast reaches the end
            while (fast) {
                fast = fast->next;
                slow = slow->next;
            }

            // Slow pointer is now at the k-th node from the end
            return slow;
        }

};

int main() {
    std::cout << "findKthFromEnd" << std::endl;
    LinkedList * list = new LinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    // list->append(6);
    list->printList();
    Node* k_th = list->findKthFromEnd(4);
    std::cout<< k_th->value<<endl;
    return 0;
}


                                                    