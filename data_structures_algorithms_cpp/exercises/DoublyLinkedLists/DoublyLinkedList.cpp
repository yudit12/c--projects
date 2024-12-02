#include "DoublyLinkedList.h"

Node::Node(int value) : value(value),next(nullptr), prev(nullptr) {};

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {};

DoublyLinkedList::DoublyLinkedList(int value):head( new Node(value)), tail(head), length(1){};

void DoublyLinkedList::printList() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->value << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

