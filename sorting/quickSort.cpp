#include <bits/stdc++.h>

using namespace std;

int partition (vector<int> &a, int low, int high);
void quickSort (vector<int> &a, int low, int high);

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, n-1);

    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

void quickSort (vector<int> &a, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

int partition (vector<int> &a, int low, int high) {
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (pivot >= a[i]) {
            i++;
        }

        while (pivot < a[j]) {
            j--;
        }

        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[j]);
    return j;
}