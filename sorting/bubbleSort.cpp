#include<bits/stdc++.h>

using namespace std;

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
};

int main() {
  int n;
  cin >> n;

  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  };

  for (int i = 0; i < n-1; i++) {
    bool swapped = false;
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
        // int temp = arr[j];
        // arr[j] = arr[j+1];
        // arr[j+1] = temp;
        swapped = true;
      };
    };
    
    if (!swapped)
      break;
  };

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  };

}