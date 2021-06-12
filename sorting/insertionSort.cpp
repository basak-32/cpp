#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  };

  for (int i = 1; i < n; i++) {
    int temp = a[i];
    int j = i-1;

    while (a[j] > temp && j >= 0) {
      a[j+1] = a[j];
      j--;
    };

    a[j+1] = temp;
  };

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  };

  return 0;
}