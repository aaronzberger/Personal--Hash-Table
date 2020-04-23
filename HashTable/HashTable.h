#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_
#include "node.h"
#include "LinkedList.h"

class HashTable {
private:
    LinkedList *arr;
    static constexpr const int def_table_size = 10;
    static constexpr const double max_table_load = 0.75;
    int hash(node &n);
public:
    HashTable(int size = def_table_size);
    ~HashTable();
    
    bool contains(node &n);
    
    void add(node &n);
    void remove(node &n);
};

#endif // _HASH_TABLE_H_
