#include <bits/stdc++.h>

using namespace std;

int decodeWays (string s);

int main () {
    string s;
    cin >> s;

    int res = decodeWays(s);

    cout << res << endl;

    return 0;
}

int decodeWays (string s) {
    int n = s.size();
    int dp[n + 1] = {};
      
    dp[0] = 1;
    dp[1] = (s[0] == '0') ? 0 : 1;
      
    for (int i = 2; i <= n; i++) {
        int oneDigit = stoi(s.substr(i - 1, i));
        int twoDigits = stoi(s.substr(i - 2, i));
        
        if (oneDigit >= 1) {
          dp[i] += dp[i - 1];
        }
        
        if (twoDigits >= 10 && twoDigits <= 26) {
          dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}