#include "HashTable.h"
#include "LinkedList.h"

HashTable::HashTable(int size) 
    : elementsBeingUsed{0}, tableSize{size} {
    arr = new LinkedList[tableSize];
}

HashTable::~HashTable() {
    std::cout << "HashTable destructor" << std::endl;
    delete [] arr;
}

bool HashTable::contains(const Node &n) const {
    const int idx {hash(n)};
    return arr[idx].contains(n);
}

void HashTable::add(Node &n) {
    if(elementsBeingUsed >= (tableSize * max_table_load))
        doubleCapacity();
    const int idx {hash(n)};
    if(arr[idx].add(n))
        elementsBeingUsed++;
}

void HashTable::remove(Node &n) {
    const int idx {hash(n)};
    if(arr[idx].remove(n))
        elementsBeingUsed--;
}

int HashTable::hash(const Node &n) const {
    int result {n.hash % tableSize};
    return result;
}

void HashTable::doubleCapacity() {
    elementsBeingUsed = 0;
    tableSize *= 2;
    LinkedList *oldArr = arr;
    arr = new LinkedList[tableSize];
    for(int i{0}; i < (tableSize / 2); i++) {
        while(!oldArr[i].isEmpty()) {
            Node *oldPtr = oldArr[i].remove();
            const int idx {hash(*oldPtr)};
            if(arr[idx].add(oldPtr))
                elementsBeingUsed++;
        }
    }
    delete [] oldArr;
}