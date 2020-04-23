#include "HashTable.h"

HashTable::HashTable(int size) {
    arr = new LinkedList[size];
}

HashTable::~HashTable() {
    delete [] arr;
}

bool HashTable::contains(node &n) {
    return arr[hash(n)].contains(n);
}
    
void HashTable::add(node &n) {
    arr[hash(n)].add(n);
}

void HashTable::remove(node &n) {
    arr[hash(n)].remove(n);
}

int HashTable::hash(node &n) {
    
}