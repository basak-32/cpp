#include<bits/stdc++.h>

using namespace std;

bool canSumHelper (vector<int> arr, int targetSum, vector<int> &memo) {
    if (targetSum == 0)
        return 1;
    
    if (targetSum < 0)
        return 0;

    if (memo[targetSum] != -1)
        return memo[targetSum];

    for (int a : arr) {
        if (canSumHelper(arr, targetSum - a, memo))
            return memo[targetSum] = 1;
    }

    return memo[targetSum] = 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int targetSum;
    cin >> targetSum;

    vector<int> memo(targetSum + 1, -1);
    memo[0] = 1;

    canSumHelper(arr, targetSum, memo);

    if (memo[targetSum])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}