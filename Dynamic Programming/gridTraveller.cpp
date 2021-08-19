#include<bits/stdc++.h>

using namespace std;

int gridTravellerHelper (int x, int y, vector<vector<int>> &memo) {
    if (x == 1 && y == 1)
        return 1;

    if (x == 0 || y == 0)
        return 0;

    if (memo[x][y] != -1)
        return memo[x][y];

    return memo[x][y] = gridTravellerHelper(x, y - 1, memo) + gridTravellerHelper(x - 1, y, memo);
}

int main() {
    int x, y;
    cin >> x >> y;

    vector<vector<int>> memo(x + 1, vector<int> (y + 1, -1));

    cout << gridTravellerHelper(x, y, memo) << endl;

    return 0;
}