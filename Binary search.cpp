#include<bits/stdc++.h>
using namespace std;
void binary_search(int l, int r, int array[], int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (array[m] == key) {
            std::cout << key << " exists";
            return;
        }
        if (array[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    std::cout << "Cannot find";
}

int main() {
    int array[10];
    for(int i=0; i<10; i++) {
        cin >> array[i];
    }
    int key; cin >> key;
    binary_search(0,9,array,key);
}