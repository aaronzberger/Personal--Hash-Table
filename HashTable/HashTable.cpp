#include "HashTable.h"

HashTable::HashTable(int size) 
    : elementsBeingUsed{0}, table_size{size} {
    arr = new LinkedList[table_size];
}

HashTable::~HashTable() {
    //TODO: Delete each LinkedList in the array
    delete [] arr;
}

bool HashTable::contains(const node &n) const {
    return arr[hash(n)].contains(n);
}

//Called from the user in order to add elements to the Hash Table
void HashTable::add(node &n) {
    if(elementsBeingUsed >= (table_size * max_table_load))
        doubleCapacity();
    if(arr[hash(n)].add(n))
        elementsBeingUsed++;
}

//Called from the doubleCapacity() method to efficiently rehash
//By simply moving the pointer to a new LinkedList, no malloc is required.
void HashTable::add(node *ptr) {
    if(arr[hash(*ptr)].add(ptr))
        elementsBeingUsed++;
}

void HashTable::remove(node &n) {
    if(arr[hash(n)].remove(n))
        elementsBeingUsed--;
}

int HashTable::hash(const node &n) const {
    int result = n.age;
    if(n.name != "") {
        result += static_cast<int>((n.name)[0]);
        result += static_cast<int>((n.name)[(n.name).length() - 1]);
    }
    return (result % table_size);
}

void HashTable::doubleCapacity() {
    elementsBeingUsed = 0;
    table_size *= 2;
    LinkedList *oldArr = arr;
    arr = new LinkedList[table_size];
    for(int i{0}; i < (table_size / 2); i++) {
        while(!oldArr[i].isEmpty())
            add(oldArr[i].remove());
    }
    delete [] oldArr;
}