#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_
#include "Node.h"
#include "LinkedList.h"

class HashTable {
private:
    LinkedList *arr;
    static constexpr const int def_table_size = 10;
    static constexpr const double max_table_load = 0.75;
    int elementsBeingUsed;
    int tableSize;
    int hash(const Node &n) const;
    void doubleCapacity();
public:
    HashTable(int size = def_table_size);
    ~HashTable();
    
    bool contains(const Node &n) const;
    
    void add(Node &n);
    void remove(Node &n);
};

#endif // _HASH_TABLE_H_
