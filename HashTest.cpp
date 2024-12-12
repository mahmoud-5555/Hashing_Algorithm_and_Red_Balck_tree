#include <iostream>
#include <cassert>
#include "HashTable.cpp"

void testHashTableDivision() {
    HashTableDivision ht(10);
    assert(ht.insertElement(5) != -1);
    assert(ht.searchElement(5) != -1);
    assert(ht.deleteElement(5) != -1);
    assert(ht.searchElement(5) == -1);
}

void testHashTableMultiplication() {
    HashTableMultiplication ht(10);
    assert(ht.insertElement(5) != -1);
    assert(ht.searchElement(5) != -1);
    assert(ht.deleteElement(5) != -1);
    assert(ht.searchElement(5) == -1);
}

void testHashTableMidSquareMethod() {
    HashTableMidSquareMethod ht(10);
    assert(ht.insertElement(5) != -1);
    assert(ht.searchElement(5) != -1);
    assert(ht.deleteElement(5) != -1);
    assert(ht.searchElement(5) == -1);
}

void testHashTableFoldingMethod() {
    HashTableFoldingMethod ht(10);
    assert(ht.insertElement(5) != -1);
    assert(ht.searchElement(5) != -1);
    assert(ht.deleteElement(5) != -1);
    assert(ht.searchElement(5) == -1);
}
//tested

void testLinkedlist() {
    Linkedlist ll;
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);
    ll.insert(8);
    ll.insert(9);
    ll.insert(10);
    ll.insert(11);
    assert(ll.search(5) == true);
    assert(ll.remove(5) == true);
    assert(ll.search(5) == false);
    assert(ll.remove(5) == false);
    assert(ll.search(6) == true);
    assert(ll.remove(6) == true);
    assert(ll.search(6) == false);
    assert(ll.remove(6) == false);
    assert(ll.search(11) == true);
    assert(ll.remove(11) == true);
    assert(ll.search(11) == false);
    assert(ll.remove(11) == false);
    assert(ll.search(12) == false);
    assert(ll.remove(12) == false);
    assert(ll.search(13) == false);
    assert(ll.remove(13) == false);
    assert(ll.search(9) == true);
    assert(ll.remove(9) == true);
    assert(ll.search(9) == false);
    assert(ll.remove(9) == false);
    ll.removeall();
    assert(ll.search(10) == false);
    assert(ll.remove(10) == false);
    assert(ll.search(10) == false);
    assert(ll.remove(10) == false);

}

void testHashTableChaining() {
    HashTableChaining ht(10);
    ht.insertElement(5);
    assert(ht.searchElement(5) != -1);
    ht.deleteElement(5);
    assert(ht.searchElement(5) == -1);
}

void testHashTableOpenAddressing() {
    HashTableOpenAddressing ht(10);
    assert(ht.insertElement(5) != -1);
    assert(ht.searchElement(5) != -1);
    assert(ht.deleteElement(5) != -1);
    assert(ht.searchElement(5) == -1);
}

void testHashTableDoubleHashing() {
    HashTableDoubleHashing ht(10);
    assert(ht.insertElement(5) != -1);
    assert(ht.searchElement(5) != -1);
    assert(ht.deleteElement(5) != -1);
    assert(ht.searchElement(5) == -1);
}

int main() {
    testHashTableDivision();
    testHashTableMultiplication();
    testHashTableMidSquareMethod();
    testHashTableFoldingMethod();
    testLinkedlist();
    testHashTableChaining();
    testHashTableOpenAddressing();
    testHashTableDoubleHashing();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}