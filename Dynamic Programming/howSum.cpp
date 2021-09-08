#include<bits/stdc++.h>

using namespace std;

void howSumHelper (int t, vector<int> arr, vector<int> res) {
    if (t == 0) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }

    if (t < 0)
        return;

    for (int i = 0; i < arr.size(); i++) {
        res.push_back(arr[i]);
        howSumHelper(t - arr[i], arr, res);
        res.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int targetSum;
    cin >> targetSum;

    vector<int> res;
    howSumHelper(targetSum, arr, res);

    return 0;
}