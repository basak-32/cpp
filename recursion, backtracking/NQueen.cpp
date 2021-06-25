#include <bits/stdc++.h>
#define N 4

using namespace std;

bool isSafe (int mat[N][N], int row, int col) {
  for (int i = 0; i <= row; i++) {
    if (mat[i][col])
      return false;
  }

  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (mat[i][j])
      return false;
  }

  for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
    if (mat[i][j])
      return false;
  }

  return true;
}

bool nQueen (int mat[N][N], int row) {
  if (row == N)
    return true;

  for (int col = 0; col < N; col++) {
    if (isSafe(mat, row, col)) {
      mat[row][col] = 1;
      if (nQueen(mat, row+1))
        return true;
      mat[row][col] = 0;
    }
  }

  return false;
}

int main () {
  int mat[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = 0;
    }
  }

  if (nQueen(mat, 0)) {
    cout << "N-Queen possioble" << endl;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "N-Queen not possible!" << endl;
  }

  return 0;
}