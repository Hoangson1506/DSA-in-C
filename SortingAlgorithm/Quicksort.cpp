#include<bits/stdc++.h>
using namespace std;
int partrition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}
void quick_sort(int array[], int l, int r) {
    if(l<r) {
        int j = partrition(array, l, r);
        quick_sort(array,l,j-1);
        quick_sort(array, j+1, r); 
    }
}
int main() {
    int n; cin >> n;
    int array[n];
    for(int i=0; i<n; i++) {
        cin >> array[i];
    }
    quick_sort(array, 0, n-1);
    for(int i=0; i<n; ++i) {
        cout << array[i] << " ";
    }
}