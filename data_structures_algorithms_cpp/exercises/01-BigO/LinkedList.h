#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node {
public:
    int value;
    Node *next;

    Node(int value);
    public:
        int getValue() const;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value);
    LinkedList();
    void printList();
    ~LinkedList();
    void append(int value);
    void deleteLast();
    Node* getHead() const;
    Node* getTail() const;
    int getLength() const;
};

#endif // LINKEDLIST_H