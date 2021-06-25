#include<bits/stdc++.h>

using namespace std;

void permute(string s, int l, int r);

int main () {
  string s;
  cin >> s;

  int n = s.size();

  permute(s, 0, n-1);
}

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void permute(string s, int l, int r) {
  if (l == r)
    cout << s << endl;
  else {
    for (int i = l; i <= r; i++) {
      swap(&s[l], &s[i]);
      permute(s, l+1, r);
      swap(&s[l], &s[i]);
    }
  }
}