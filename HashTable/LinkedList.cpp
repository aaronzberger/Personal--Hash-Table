#include "LinkedList.h"
#include <string>
#include <iostream>
#include "Node.h"
#include "stdio.h"

LinkedList::LinkedList() 
    : head{nullptr} {}


LinkedList::~LinkedList() {
    std::cout << "LinkedList destructor" << std::endl;
    LinkedListNode *oldHead = head;
    while(oldHead != nullptr) {
        head = head->next;
        delete oldHead;
    }
}

//Returns whether this is the first time an element is being put into this index.
//Used to calculate load factor for possible resizing of the hash table.
bool LinkedList::add(Node &n) {
    LinkedListNode *newNode = new LinkedListNode(n);
    return add(newNode);
}

//Usedd when rehashing by the Hash Table.
bool LinkedList::add(Node *ptr) {
    LinkedListNode *newNode = new LinkedListNode(ptr);
    return add(newNode);
}

//Used when rehasing elements and by the other add function.
//Inserts the pointer into the array with no new malloc.
bool LinkedList::add(LinkedListNode *ptr) {
    if(head == nullptr) {
        ptr->next = nullptr;
        head = ptr;
        return true;
    }
    ptr->next = head;
    head = ptr;
    return false;
}

//Returns whether this cell of the Hash Table (this LinkedList) is now empty.
//Used to calculate load factor for possible resizing of the hash table.
bool LinkedList::remove(Node &n) {
    if(head == nullptr)
        perror ("tried to remove an element from an empty LinkedList in remove()");
        //throw std::runtime_error("tried to remove an element from an empty LinkedList in remove()");
    if(*head == n) {
        LinkedListNode *oldHead = head;
        head = head->next;
        delete oldHead;
        return true;
    }
    LinkedListNode *traverser = head;
    while(*(traverser->next) != n) {
        if(traverser->next == nullptr)
            perror ("traverser reached end of linked list in removeNode()");
            //throw std::runtime_error("traverser reached end of linked list in removeNode()");
        traverser = traverser->next;
    }
    LinkedListNode *deletion = traverser->next;
    traverser->next = deletion->next;
    delete deletion;
    if(head == nullptr)
        return true;
    return false;
}

bool LinkedList::contains(const Node &n) const {
    if(head == nullptr)
        return false;
    LinkedListNode *traverser = head;
    while(traverser != nullptr) {
        if(*traverser == n) {
            return true;
        }
        traverser = traverser->next;
    }
    return false;
}

Node* LinkedList::remove() {
    if(head == nullptr)
        perror ("tried to remove an element when the LinkedList is empty");
        //throw std::runtime_error("tried to remove an element when the LinkedList is empty");
    LinkedListNode *oldHead = head;
    head = head->next;
    Node *toRemove = (*oldHead).n;
    return toRemove;
}

bool operator!=(const LinkedListNode &lhs, const Node &rhs) {
    if(lhs.n == nullptr)
        return false;
    return (lhs.n->name != rhs.name ||
            lhs.n->age != rhs.age);
}

bool operator==(const LinkedListNode &lhs, const Node &rhs) {
    if(lhs.n == nullptr)
        return false;
    return (lhs.n->name == rhs.name &&
            lhs.n->age == rhs.age);
}
