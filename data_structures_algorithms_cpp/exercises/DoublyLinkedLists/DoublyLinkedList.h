#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>


class Node {
public:
    int value;
    Node *next;
    Node* prev;

    Node(int value);
    public:
        int getValue() const;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList();
    DoublyLinkedList(int value);
    void printList();

};

#endif // DOUBLYLINKEDLIST_H