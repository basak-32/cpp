#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, int l, int mid, int r);
void mergeSort(vector<int> &a, int l, int r);

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, n-1);

    for (int num : a)
        cout << num << " ";

    return 0;
}

void mergeSort(vector<int> &a, int l, int r) {
    if (l < r) {
        int mid = (l +  r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

void merge(vector<int> &a, int l, int mid, int r){
    vector<int> b(a.size());
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= r)
    {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    while (j <= r)
    {
        b[k++] = a[j++];
    }
    
    for (k = l; k <= r; k++) {
        a[k] = b[k];
    }
}