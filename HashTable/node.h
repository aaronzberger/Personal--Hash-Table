#ifndef _NODE_H_
#define _NODE_H_
#include <string>

struct node {
    friend bool operator!=(const node &lhs, const node &rhs);
    friend bool operator==(const node &lhs, const node &rhs);
    std::string name;
    int age;
    node *next;
};

#endif