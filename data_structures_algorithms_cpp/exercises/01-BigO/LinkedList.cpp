#include "LinkedList.h"
#include <cassert> 

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
        delete tail;
        tail = temp;
        tail->next = nullptr;
        
    }
    length--;
}

void LinkedList::prepend(int value){
    Node * newNode = new Node(value);
    
    if (head)
    {
        newNode->next = head;
        head = newNode;
    }
    else{
        head= newNode;
        tail = newNode;
    }
    length++;

}

void LinkedList::deleteFirst(){
    if (head == nullptr){
        return;
    }
    if (head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
         Node * temp= head;
         head = head->next;
         delete temp;
    }
    length--;
    
    //Assert that the length is never negative (helps avoid bugs in the future)
    assert(length >= 0); 
}

Node* LinkedList::get(int index) {
    if (index < 0 || index >= length) {
        return nullptr; // Index is out of bounds
    }

    Node* temp = head;
    int counter = index; // Start from the given index

    while (counter != 0) {
        temp = temp->next;
        counter--; // Move to the next node
    }

    return temp; // Return the node at the given index
}

bool LinkedList::set(int index, int value) {
    // Use the get method to locate the node
    Node* temp = get(index);
    if (temp == nullptr) {
        return false; // Index out of bounds
    }

    // Update the node's value
    temp->value = value;
    return true;
}

bool LinkedList::insert(int index, int value){
    if (index < 0 || index > length){
        return false;
    }
    if (index == 0){
        prepend(value); // length upated in the function 
        return true;
    }
    if (index == length){
        append(value); // length upated in the function
        return true;
    }
    Node * newNode = new Node(value);
    Node* temp = get(index-1);
    if (temp == nullptr){
        delete newNode;
        return false;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
}

void  LinkedList::deleteNode(int index){
    if (index < 0 || index >= length) return;
    if (index == 0){
        deleteFirst();  // length upated in the function
        return; 
    }
    else if (index == length){
        deleteLast();  // length upated in the function
        return; 
    }
    Node * prev = get(index-1);
    Node* toDel = prev->next;     // Node to delete
    prev->next = toDel->next;
    delete toDel;
    length--;

}

void LinkedList::reverse(){
    if (!head || !head->next) { // Check if the list is empty or has only one node
        return;
    }

    Node* prev = nullptr;  // Previous node, initially nullptr
    Node* temp = head;     // Current node, starting at the head
    Node* after = nullptr; // Next node, initialized later

    tail = head; // The current head will become the tail after reversal

    while (temp) { // Traverse the list
        after = temp->next; // Save the next node
        temp->next = prev;  // Reverse the current node's pointer
        prev = temp;        // Move prev forward
        temp = after;       // Move temp forward
    }

    head = prev; // Update the head to the new first node
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