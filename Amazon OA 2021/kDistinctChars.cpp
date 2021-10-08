#include<bits/stdc++.h>

using namespace std;

int helper (string s, int k);

int main () {
    string s;
    cin >> s;

    int k;
    cin >> k;

    cout << helper(s, k) - helper(s, k - 1);

    return 0;
}

int helper (string s, int k) {
    unordered_map<char, int> mp;
    int left = 0;
    int res = 0;

    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;

        while (mp.size() > k) {
            if (mp[s[left]] == 1) {
                mp.erase(s[left]);
            } else {
                mp[s[left]]--;
            }

            left++;
        }

        res += i - left + 1;
    }

    return res;
}