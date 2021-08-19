#include<bits/stdc++.h>

using namespace std;

int fib (int n) {
    int dp[n + 1] = {};
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main () {
    int n;
    cin >> n;

    cout << fib(n);

    return 0;
}