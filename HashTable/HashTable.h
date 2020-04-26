#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_
#include "Node.h"
#include "LinkedList.h"

class HashTable {
private:
    LinkedList *arr;
    static constexpr const int defTableSize = 10;
    static constexpr const double maxTableLoad = 0.75;
    bool allowDuplicates;
    int elementsBeingUsed;
    int tableSize;
    unsigned int hash(const Node &n) const;
    void doubleCapacity();
public:
    HashTable(int size = defTableSize, bool allowDuplicates = true);
    ~HashTable();
    
    bool contains(const Node &n) const;
    
    void add(Node &n);
    void remove(Node &n);
};

#endif // _HASH_TABLE_H_