#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, temp;
  vector<int> arr;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back(temp);
  };

  for (int i = 0; i < n-1; i++) {
    int min = i;
    for (int j = i+1; j < n; j++) {
      if (arr[j] < arr[min])
        min = j;
    };

    if (min != i) {
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
      
    }
  };

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}