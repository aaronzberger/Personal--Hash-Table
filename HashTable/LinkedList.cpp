#include "LinkedList.h"
#include <string>
#include <iostream>
#include "node.h"

LinkedList::LinkedList() 
    : head{nullptr} {}


LinkedList::~LinkedList() {
    node *newHead;
    while(newHead != nullptr) {
        newHead = head->next;
        delete head;
        head = newHead;
    }
}

//Returns whether this is the first time an element is being put into this index.
//Used to calculate load factor for possible resizing of the hash table.
bool LinkedList::add(node &n) {
    node *newNode = new node(n);
    if(head == nullptr) {
        newNode->next = nullptr;
        head = newNode;
        return true;
    }
    newNode->next = head;
    head = newNode;
    return false;
}

//Returns whether this cell of the array (this LinkedList) is now empty.
//Used to calculate load factor for possible resizing of the hash table.
bool LinkedList::remove(node &n) {
    node *traverser = head;
    while(*(traverser->next) != n) {
        if(traverser == nullptr)
            throw std::runtime_error("traverser reached end of linked list in removeNode()");
        traverser = traverser->next;
    }
    node *deletion = traverser->next;
    traverser->next = traverser->next->next;
    delete deletion;
    if(head == nullptr)
        return true;
    return false;
}

bool LinkedList::contains(const node &n) {
    if(head == nullptr)
        return false;
    node *traverser = head;
    while(traverser != nullptr) {
        if(*traverser == n) {
            return true;
        }
        traverser = traverser->next;
    }
    return false;
}

bool operator!=(const node &lhs, const node &rhs) {
    return (lhs.name != rhs.name ||
            lhs.age != rhs.age);
}

bool operator==(const node &lhs, const node &rhs) {
    return (lhs.name == rhs.name &&
            lhs.age == rhs.age);
}