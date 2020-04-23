#include "LinkedList.h"
#include <string>
#include <iostream>
#include "node.h"

LinkedList::LinkedList() 
    : head{nullptr} {}


LinkedList::~LinkedList() {
//ToDo
}

//Returns whether this is the first time an element is being put into this index.
//Used to calculate load factor for possible resizing of the hash table.
bool LinkedList::add(node &n) {
    node newNode(n);
    if(head == nullptr) {
        newNode.next = nullptr;
        head = &newNode;
        return true;
    }
    newNode.next = head;
    head = &newNode;
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
    traverser->next = traverser->next->next;
    
    if(head == nullptr)
        return true;
    return false;
}

bool LinkedList::contains(node &n) {
    if(head == nullptr)
        return false;
    node *traverser = head;
    while(*(traverser->next) != n) {
        if(traverser == nullptr)
            return false;
        traverser = traverser->next;
    }
    return true;
}

bool operator!=(const node &lhs, const node &rhs) {
    return (lhs.name != rhs.name ||
            lhs.age != rhs.age);
}