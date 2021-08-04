#include <bits/stdc++.h>

using namespace std;

bool isFeasible (vector<int> a, int k, int res);

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min = INT_MIN, max = 0;

    for (int num : a) {
        if (num > min) {
            min = num;
        }
        max += num;
    }

    int res = 0;

    while (min <= max) {
        int mid = (min + max) / 2;
        if (isFeasible(a, k, mid)) {
            res = mid;
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}


bool isFeasible (vector<int> a, int k, int res) {
    int student = 1, sum = 0;

    for (int num : a) {
        if ((sum + num) > res) {
            student++;
            sum = num;
        } else {
            sum += num;
        }
    }

    return (student <= k);
}