#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sl;
    cin >> sl;

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    deque<int> dq;

    for (int i = 0; i < sl; i++) {
        if (dq.empty()) {
            dq.push_front(arr[i]);
        } else {
            while (!dq.empty() && arr[i] < dq.back()) {
                dq.pop_back();
            }
            dq.push_back(arr[i]);
        }
    }

    // cout << dq.front() << endl;
    // cout << dq.back() << endl;

    // int currMin = dq.front();
    int maxOfMins = dq.front();

    int i = 1, j = sl;
    while (j < n) {
        if (arr[i - 1] == dq.front()) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[j] < dq.back()) {
            dq.pop_back();
        }
        dq.push_back(arr[j]);

        // currMin = dq.front();
        maxOfMins = max(maxOfMins, dq.front());

        // cout << "dq.front" << dq.front() << endl;
        // cout << "dq.back" << dq.back() << endl;

        i++;
        j++;
    }

    cout << maxOfMins << endl;

    return 0;
}