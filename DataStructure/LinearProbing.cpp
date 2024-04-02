#include<iostream>
#include<vector>
using namespace std;
class HashTable {
    vector<int> table;
public:
    HashTable(int size);
    void insertItem(int key);
    void deleteItem(int key);
    int searchItem(int key);
    void printTable();
    int hashFunction(int key) {
        return key % table.size();
    }
};
HashTable::HashTable(int size) {
    this->table.resize(size, -1);
}
void HashTable::insertItem(int key) {
    int index = hashFunction(key);
    while(table[index] != -1 && table[index] != key && table[index] != -2) {
        index = (index + 1) % table.size();
    }
    if(table[index] != key) {
        table[index] = key;
    }
}
void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    while(table[index] != -1) {
        if(table[index] == key) {
            table[index] = -2;
            return;
        }
        index = (index + 1) % table.size();
    }
}
int HashTable::searchItem(int key) {
    int index = hashFunction(key);
    int counter = 0;
    while(table[index] != -1 && counter++ != table.size()) {
        if(table[index] == key) {
            return index;
        }
        else index = (index + 1) % table.size();
    }
    return -1;
}
void HashTable::printTable() {
    for(int i=0; i<table.size(); i++) {
        if(table[i] != -1 && table[i] != -2) {
            cout << i << "->" << table[i] << "\n";
        }
        else {
            cout << i << "\n";
        }
    }
}
int main() {
    int a[] = {1, 3, 6, 7, 9};
    HashTable table(7);
    for(int i=0; i<5; i++) {
        table.insertItem(a[i]);
    }
    table.printTable();
    table.deleteItem(6);
    table.printTable();
    if(table.searchItem(7) != -1) cout << "yes\n";
    else cout << "no";
}