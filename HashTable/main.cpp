#include <iostream>
#include <string>
#include "node.h"
#include "HashTable.h"

int main() {
    std::cout << "=============================" << std::endl;
    
    node n1; n1.name = "Node n1"; n1.age = 10;
    node n2; n2.name = "Node n2"; n2.age = 20;
    node n3; n3.name = "Node n3"; n3.age = 30;
    node n4; n4.name = "Node n4"; n4.age = 40;
    node n5; n5.name = "Node n5"; n5.age = 50;
    node n6; n6.name = "Node n6"; n6.age = 60;
    node n7; n7.name = "Node n7"; n7.age = 70;
    
    HashTable hashTable{2};
    
    hashTable.add(n1);
    hashTable.add(n2);
    hashTable.add(n3);
        
    std::cout << std::boolalpha;
    std::cout << hashTable.contains(n1) << std::endl; //true
    std::cout << hashTable.contains(n2) << std::endl; //true
    std::cout << hashTable.contains(n4) << std::endl; //false
    std::cout << hashTable.contains(n1) << std::endl; //true
    std::cout << hashTable.contains(n7) << std::endl; //false
    
    hashTable.remove(n1);
    std::cout << hashTable.contains(n1) << std::endl; //false
    
    hashTable.add(n4);
    hashTable.add(n5);
    hashTable.add(n6);
    hashTable.add(n2);
    hashTable.add(n7);

    std::cout << "=============================" << std::endl;
    return 0;
}