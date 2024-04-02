#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int l, int m, int r) {
    int n1, n2, i, j, k;
    n1 = m - l + 1;
    n2 = r - m;
    vector<int> L(n1), R(n2);
    for(i=0; i<n1; i++) {
        L[i] = v[l+i];
    }
    for(j=0; j<n2; j++) {
        R[j] = v[m+1+j];
    }
    i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while(j<n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int> &v, int n) {
    for (int size = 1; size < n; size *= 2) {
        for (int l = 0; l < n-1; l += 2 * size) {
            int m = min(l + size - 1, n-1);
            int r = min(l + 2 * size - 1, n-1);
            merge(v, l, m, r);
        }
    }
}
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    merge_sort(v,v.size());
    for(int i=0; i<n; i++) {
        cout << v[i] << " ";
    }
}