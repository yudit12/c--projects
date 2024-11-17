#include "LinkedList.h"

Node::Node(int value) {
    this->value = value;
    next = nullptr;
}

int Node::getValue() const {
    return value;
}

LinkedList::LinkedList(int value): head (new Node(value)),tail(head),length(1){};


LinkedList::LinkedList() : head(nullptr), tail(nullptr), length(0) {};

void LinkedList::printList() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->value << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
}

void LinkedList::append(int value) {
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

// void LinkedList::deleteLast() {
//     if (head == nullptr) {
//         return;
//     }
//     Node* temp = head;
//     Node* prev = head;
//     while (temp->next) {
//         temp = temp->next;
//         tail = temp;
//     }
//     delete temp;
//     length--;
// }

void LinkedList::deleteLast() {
    if (head == nullptr) {
        // The list is empty, nothing to delete
        return;
    }

    // If there is only one node in the list
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        // Traverse the list to find the second-to-last node
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        // Delete the last node (tail)
        delete tail;
        // Update the second-to-last node's next pointer to nullptr
        temp->next = nullptr;
        // Update the tail pointer to the second-to-last node
        tail = temp;
    }
    length--;
}

Node* LinkedList::getHead() const{
    if (head){
        std::cout << "head: " << head->value << std::endl;
    }
    // if (head == nullptr) throw std::runtime_error("List is empty");
    return head;
}

Node* LinkedList::getTail() const{
    if (tail){
        std::cout << "tail: " << tail->value << std::endl;
    }
    // if (tail == nullptr) throw std::runtime_error("List is empty");
    return tail;
}

int LinkedList::getLength() const {
    std::cout << "length: " << length << std::endl;
    return length;
}