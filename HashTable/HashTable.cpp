#include "HashTable.h"

HashTable::HashTable(int size) 
    : elementsBeingUsed{0}, table_size{size} {
    arr = new LinkedList[table_size];
}

HashTable::~HashTable() {
    delete [] arr;
}

bool HashTable::contains(const node &n) {
    return arr[hash(n)].contains(n);
}
    
void HashTable::add(node &n) {
    if(elementsBeingUsed > (table_size * max_table_load))
        doubleCapacity();
    if(arr[hash(n)].add(n))
        elementsBeingUsed++;
}

void HashTable::remove(node &n) {
    if(arr[hash(n)].remove(n))
        elementsBeingUsed--;
}

int HashTable::hash(const node &n) {
    int result = n.age;
    if(n.name != "") {
        result += static_cast<int>((n.name)[0]);
        result += static_cast<int>((n.name)[(n.name).length() - 1]);
    }
    return (result % table_size);
}

void HashTable::doubleCapacity() {
    LinkedList *newArr = new LinkedList[table_size * 2];
    for(int i{0}; i < table_size; i++)
        newArr[i] = arr[i];
    table_size *= 2;
    delete [] arr;
}