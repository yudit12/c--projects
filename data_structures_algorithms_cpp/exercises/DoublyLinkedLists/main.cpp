#include <iostream>
#include "DoublyLinkedList.h"  // Include the header file for LinkedList

int main() {
    std::cout << "DoublyLinkedList main" << std::endl;

    DoublyLinkedList* myDll = new DoublyLinkedList(7);
    myDll->printList();

    return 0;
}