#include<bits/stdc++.h>

using namespace std;

bool comp (pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int rem;
    cin >> rem;

    unordered_map<int, int> mp;

    for (int num : arr) {
        mp[num]++;
    }

    multimap<int, int> mm;

    for (auto &it : mp) {
        mm.insert({it.second, it.first});
    }

    for (auto &it : mm) {
        if (it.first <= rem) {
            rem -= it.first;
            mm.erase(it.first);
        } else {
            break;
        }
    }

    cout << mm.size() << endl;


    return 0;
}