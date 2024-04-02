#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int array[], int n) {
    for(int i=n-1; i>=1; i--) {
        for(int j=0; j<=i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++) {
        cin >> array[i];
    }
    bubble_sort(array,n);
    for(int i=0; i<n; i++) {
        cout << array[i] << " ";
    }
}