#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "node.h"
#include <string>
#include <iostream>

class LinkedList {
    friend bool operator==(const node &lhs, const node &rhs);
    friend bool operator!=(const node &lhs, const node &rhs)
private:
    node *head;
public:
    LinkedList();
    ~LinkedList();
    
    bool add(node &n);
    bool remove(node &n);
    
    bool contains(const node &n);
};

#endif // _LINKEDLIST_H_
