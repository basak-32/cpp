#include<bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int>> locations;
    for (int i = 0; i < n; i++) {
        vector<int> v(2);
        cin >> v[0] >> v[1];
        locations.push_back(v);
    }

    int k;
    cin >> k;

    priority_queue<vector<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(locations[i]);
    }

    for (int i = k; i < n; i++) {
        int x1 = locations[i][0];
        int y1 = locations[i][1];

        int x2 = pq.top()[0];
        int y2 = pq.top()[1];

        if ((x1 * x1 + y1 * y1) == (x2 * x2 + y2 * y2)) {
            if (x1 < x2) {
                pq.pop();
                pq.push(locations[i]);
            }
        }

        if ((x1 * x1 + y1 * y1) < (x2 * x2 + y2 * y2)) {
            pq.pop();
            pq.push(locations[i]);
        }
    }

    vector<vector<int>> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }

    cout << "k Closest Points are: " << endl;
    for (int i = 0; i < k; i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}