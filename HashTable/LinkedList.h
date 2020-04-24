#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "node.h"
#include <string>
#include <iostream>

class LinkedList {
private:
    node *head;
public:
    LinkedList();
    ~LinkedList();
        
    bool add(node &n);
    bool add(node *ptr);
    bool remove(node &n);
    
    node* remove();
    
    bool contains(const node &n);
    
    bool isEmpty() { return (head == nullptr); }
};

#endif // _LINKEDLIST_H_
