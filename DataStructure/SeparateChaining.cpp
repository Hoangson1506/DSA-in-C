#include<iostream>
#include<list>
using namespace std;
class HashTable {
    //number of buckets
    int buckets; 
    list<int> *table;
public:
    HashTable(int V);
    void insertItem(int key);
    void deleteItem(int key);
    bool searchItem(int key);
    int hashFunction(int key) {
        return (key % buckets);
    } 
    void printTable();
};

HashTable::HashTable(int b) {
    this->buckets = b;
    table = new list<int>[buckets];
}
void HashTable::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}
void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    list<int> :: iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++) {
        if(*i == key) break;
    }
    if(i != table[index].end()) 
        table[index].erase(i);
}
bool HashTable::searchItem(int key) {
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key) {
            return true; 
        }
    }
    return false; 
}
void HashTable::printTable() {
    for(int i=0; i<buckets; i++) {
        cout << i;
        for(auto x : table[i]) {
            cout << " -> " << x;
        }
        cout << "\n";
    }
}
int main() {
    int a[] = {15, 11, 27, 8, 12};
    HashTable table(7);
    for(int i=0; i<5; i++) {
        table.insertItem(a[i]);
    }
    table.printTable();
    table.deleteItem(8);
    table.printTable();
    if(table.searchItem(7)) cout << "yes\n";
    else cout << "no";
}