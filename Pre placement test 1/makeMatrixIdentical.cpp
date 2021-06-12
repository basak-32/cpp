#include<bits/stdc++.h>

using namespace std;

int solve (int a[100][100], int b[100][100], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] -= b[i][j];
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] - a[i][0] - a[0][j] + a[0][0] != 0)
        return -1;
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++)
    result += abs(a[i][0]);

  for (int j = 0; j < m; j++)
    result += abs(a[0][j] - a[0][0]);

  return result;
}

int main() {
  int n, m;
  cin >> n >> m;

  int a[100][100], b[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }

  cout << solve(a, b, n, m) << endl;

  return 0;
}