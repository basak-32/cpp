#include<bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> arrTime(n), dir(n);

    for (int i = 0; i < n; i++) {
        cin >> arrTime[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> dir[i];
    }

    queue<int> entrance, exit;
    int currSec = 0, prevOp = -1;

    vector<int> res(n);

    int i = 0;
    while (i < n) {
        while (arrTime[i] == currSec && i < n) {
            if (dir[i] == 0) {
                entrance.push(i);
            } else {
                exit.push(i);
            }

            i++;
        }

        if (!entrance.empty() && !exit.empty()) {
            if (prevOp == 0) {
                res[entrance.front()] = currSec;
                entrance.pop();
                prevOp = 0;
            } else {
                res[exit.front()] = currSec;
                exit.pop();
                prevOp = 1;
            }
        } else if (!entrance.empty()) {
            res[entrance.front()] = currSec;
            entrance.pop();
            prevOp = 0;
        } else if (!exit.empty()) {
            res[exit.front()] = currSec;
            exit.pop();
            prevOp = 1;
        } else {
            prevOp = -1;
        }

        currSec++;
    }

    while (!entrance.empty() || !exit.empty()) {
        if (!entrance.empty() && !exit.empty()) {
            if (prevOp == 0) {
                res[entrance.front()] = currSec;
                entrance.pop();
                prevOp = 0;
            } else {
                res[exit.front()] = currSec;
                exit.pop();
                prevOp = 1;
            }
        } else if (!entrance.empty()) {
            res[entrance.front()] = currSec;
            entrance.pop();
            prevOp = 0;
        } else if (!exit.empty()) {
            res[exit.front()] = currSec;
            exit.pop();
            prevOp = 1;
        } else {
            prevOp = -1;
        }

        currSec++;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}