#include<bits/stdc++.h>
using namespace std;
int getMax(vector<int> &array) {
    int max = INT_MIN;
    for(int i=0; i<array.size(); i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
void sortByDigit(vector<int> &array, int exp) {
    vector<int> sorted[10];
    for(int i=0; i<array.size(); i++) {
        int index = (array[i]/exp)%10;
        sorted[index].push_back(array[i]);
    }
    int k=0;
    while(k<array.size()) {
        for(int i=0; i<10; i++) {
            for(int j=0; j<sorted[i].size(); j++) {
                array[k++] = sorted[i][j];
            }
        }
    }
} 
void radixSort(vector<int> &array) {
    int m = getMax(array);
    for(int exp = 1; m/exp>0; exp*=10) {
        sortByDigit(array, exp);
    }
}
int main() {
    int n; cin >> n;
    vector<int> array(n);
    for(int i=0; i<n; i++) {
        cin >> array[i];
    }
    radixSort(array);
    for(int i=0; i<n; i++) {
        cout << array[i] << " ";
    }
}