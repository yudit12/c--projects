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
    void prepend(int value);
    void deleteFirst();
    Node* get(int index); // get node by index
    bool set(int index, int value);//set node in given index to the given value;
    bool insert(int index, int value);
    void  deleteNode(int index);
    void  reverse();
    Node* getHead() const;
    Node* getTail() const;
    int getLength() const;
};

#endif // LINKEDLIST_H