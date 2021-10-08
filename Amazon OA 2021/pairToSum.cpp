#include<bits/stdc++.h>

using namespace std;

int main () {
    int  n;
    cin >> n;

    int s;
    cin >> s;

    vector<int> arr(s);
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }

    int target = n - 30;
    int i = 0, j = s - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == target) {
            cout << i << " " << j << endl;
            break;
        }

        if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    // int availableSpace = n - 30;
    // int a = -1, b = -1;

    // unordered_set<int> st;
    // for (int i = 0; i < s; i++) {
    //     st.insert(arr[i]);
    // }

    // for (int i = 0; i < s; i++) {
    //     if (st.find(availableSpace - arr[i]) != st.end()) {
    //         a = i;
    //         for (int j = s - 1; j >= 0; j--) {
    //             if (arr[j] == availableSpace - arr[i] && i != j) {
    //                 b = j;
    //                 break;
    //             }
    //         }

    //         if (a != -1 && b != -1) break;
    //     }
    // }

    // if (a != -1 && b != -1)
    //     cout << a << " " << b << endl;
    // else
    //     cout << -1 << " " << -1 << endl;

    
    return 0;
}