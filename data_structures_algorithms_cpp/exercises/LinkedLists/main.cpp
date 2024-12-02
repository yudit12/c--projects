#include <iostream>
#include "LinkedList.h"  // Include the header file for LinkedList

int main() {
    std::cout << "LinkedList main " << std::endl;

    LinkedList* list = new LinkedList();
    list->append(10);
    list->append(20);
    list->printList();

    return 0;
}