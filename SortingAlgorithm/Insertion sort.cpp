#include<bits/stdc++.h>
using namespace std;
void move_right(int array[], int i, int j) {
    while(i > j) {
        array[i] = array[i-1];
        i--;
    }
}
void insertion_sort(int array[], int n) {
    for(int i = 1; i<n; i++) {
        int temp = array[i];
        for(int j=0; j<i; j++) {
            if(array[i] <= array[j]) {
                move_right(array, i, j);
                array[j] = temp;
                break;
            }
        }
    }
}
int main() {
    int array[8];
    for(int i=0; i<8; i++) {
        cin >> array[i];
    }
    insertion_sort(array, 8);
    for(int i=0; i<8; i++) {
        cout << array[i] << " ";
    }
}