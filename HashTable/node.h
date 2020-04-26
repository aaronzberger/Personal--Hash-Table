#ifndef _NODE_H_
#define _NODE_H_
#include <string>
#include <cmath>

class LinkedListNode;

class Node {
    friend bool operator!=(const LinkedListNode &lhs, const Node &rhs);
    friend bool operator==(const LinkedListNode &lhs, const Node &rhs);
public:
    std::string name;
    int age;
    int hash;
    
    Node() {
        int result = static_cast<int>(age * 1.75);
        if(name != "") {
            result += static_cast<int>((name)[0]);
            result += static_cast<int>((name)[name.length() - 1]);
        }
        hash = abs(result);
    }
};

#endif