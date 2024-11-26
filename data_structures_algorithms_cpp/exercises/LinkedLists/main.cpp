#include <iostream>
#include "LinkedList.h"  // Include the header file for LinkedList

int main() {
    std::cout << "Running data_structures_algorithms_cpp program!" << std::endl;

    LinkedList list;
    list.append(10);
    list.append(20);
    list.printList();

    return 0;
}