#include<iostream>

using namespace std;

int main() {
  int t;
  int n, k, d, a;
  int total = 0;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n >> k >> d;
    
    for (int j = 0; j < n; j++) {
      cin >> a;
      total += a;
    };

    if (total < k) {
      cout << 0;
    } else if (total >= (k * d)) {
      cout << d;
    } else {
      cout << ((k * d) / total);
    };
  };
};