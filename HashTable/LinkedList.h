#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <string>
#include <iostream>
#include "Node.h"

class LinkedListNode;

class LinkedList {
private:
    LinkedListNode *head;
    bool add(LinkedListNode *ptr);
    bool allowDuplicates;
public:
    LinkedList(bool allowDuplicates = true);
    ~LinkedList();
        
    bool add(Node &n);
    bool add(Node *ptr);
    bool remove(Node &n);
    
    Node* remove();
    
    bool contains(const Node &n) const;
    
    bool isEmpty() { return (head == nullptr); }
};

class LinkedListNode {
    friend bool operator!=(const LinkedListNode &lhs, const Node &rhs);
    friend bool operator==(const LinkedListNode &lhs, const Node &rhs);
private:

public:
    Node *n;
    LinkedListNode *next;
    LinkedListNode(const Node &n) 
        : next{nullptr} {
        Node *newNode = new Node(n);
        this->n = newNode;
    }
    LinkedListNode(Node *ptr) 
        : n{ptr}, next{nullptr} {}
    ~LinkedListNode() {
        //std::cout << "LinkedListNode destructor" << std::endl;
        delete n;
    }
};

#endif // _LINKEDLIST_H_
