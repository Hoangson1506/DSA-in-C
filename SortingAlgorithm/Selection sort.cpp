#include<bits/stdc++.h>
using namespace std;
void print_array(int array[], int n) {
    for(int i=0; i<n; i++) {
        cout << array[i] << " ";
    }
}
void selection_sort(int array[], int i, int n) {
    if(i==n) {
        print_array(array, n);
        return;
    }
    int minn = 1000000000;
    int index = -1;
    for(int j=i; j<n; j++) {
        if(array[j] < minn) {
            minn = array[j];
            index = j;
        }
    }
    swap(array[i], array[index]);
    selection_sort(array, i+1, n);
}
int main() {
    int array[9];
    for(int i=0; i<9; i++) {
        cin >> array[i];
    }
    selection_sort(array, 0, 9);
}