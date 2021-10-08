#include<bits/stdc++.h>

using namespace std;

long long nCr (int n, int r);
long long fact (int n);
map<int, long long> mp;

int main () {
    int num;
    cin >> num;

    vector<int> skills(num);
    for (int i = 0; i < num; i++) {
        cin >> skills[i];
    }

    int minNum;
    int minLevel, maxLevel;
    cin >> minNum >> minLevel >> maxLevel;

    int n = 0;
    for (int i = 0; i < num; i++) {
        if (skills[i] >= minLevel && skills[i] <= maxLevel) {
            n++;
        }
    }

    if (n < minNum)
        return 0;

    long long res = 0;
    for (int i = minNum; i <= n; i++) {
        res += nCr(n, i);
    }

    cout << res << endl;

    return 0;
}

long long nCr (int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

long long fact (int n) {
    if (n == 0 || n == 1)
        return 1;

    if (mp.find(n) != mp.end()) {
        return mp[n];
    } else {
        return mp[n] = n * fact(n - 1);
    }
}

// long long fact (int n) {
//     if (n == 0 || n == 1)
//         return 1;

//     return n * fact(n - 1);
// }