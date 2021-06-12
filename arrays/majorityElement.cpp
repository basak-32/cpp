#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  };

  int count = 1;
  int maxElem = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] == maxElem)
      count++;
    else
      count--;

    if (count == 0) {
      count++;
      maxElem = arr[i];
    };
  };

  count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == maxElem)
      count++;
  };

  if (count > n/2)
    cout << maxElem << endl;
  else
    cout << "No M.E." << endl;

  return 0;
}