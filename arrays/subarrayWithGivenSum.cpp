#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, target;
  cin >> n >> target;

  vector<int> a;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }

  int start = 0, sum = a[0];
  for (int i = 1; i <= n; i++) {
    while (sum > target && start < i-1) {
      sum -= a[start];
      start++;
    }

    if (sum == target) {
      cout << "From index " << start << " to " << i-1;
      return 0;
    }

    if (i < n)
      sum += a[i];
  }
  
  cout << -1;

  return 0;
}