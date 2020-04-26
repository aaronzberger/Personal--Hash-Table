#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "stdio.h"

int main() {
    std::cout << "=============================" << std::endl;
    
    Node n1; n1.name = "Node n1"; n1.age = 10;
    Node n2; n2.name = "Node n2"; n2.age = 20;
    Node n3; n3.name = "Node n3"; n3.age = 30;
    Node n4; n4.name = "Node n4"; n4.age = 40;
    Node n5; n5.name = "Node n5"; n5.age = 50;
    Node n6; n6.name = "Node n6"; n6.age = 60;
    Node n7; n7.name = "Node n7"; n7.age = 70;
    
    HashTable hashTable{3};
    
    hashTable.add(n1);
    hashTable.add(n2);
    hashTable.add(n3);
        
    std::cout << std::boolalpha;
    
    assert(hashTable.contains(n1));
    assert(hashTable.contains(n2));
    assert(!hashTable.contains(n4));
    assert(hashTable.contains(n1));
    assert(!hashTable.contains(n7));

    
    hashTable.remove(n1);
    assert(!hashTable.contains(n1));
    
    hashTable.add(n4);
    hashTable.add(n5);
    hashTable.add(n6);
    hashTable.add(n2);
    hashTable.add(n7);
    
    hashTable.remove(n7);
    assert(!hashTable.contains(n7));
    
    perror("Hello Test");

    std::cout << "=============================" << std::endl;
    return 0;
}