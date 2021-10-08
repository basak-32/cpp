#include<bits/stdc++.h>

using namespace std;

void dfs (vector<vector<int>> grid, int i, int j, int currDis, int &minDis);

int main () {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int minDis = INT_MAX;
    
    dfs (grid, 0, 0, 0, minDis);

    if (minDis == INT_MAX)
        cout << -1 << endl;
    else
        cout << minDis << endl;


    return 0;
}

void dfs (vector<vector<int>> grid, int i, int j, int currDis, int &minDis) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == -1) {
        return;
    }

    if (grid[i][j] == 9) {
        minDis = min(minDis, currDis);
        return;
    }

    grid[i][j] = -1;

    dfs(grid, i - 1, j, currDis + 1, minDis);
    dfs(grid, i, j - 1, currDis + 1, minDis);
    dfs(grid, i + 1, j, currDis + 1, minDis);
    dfs(grid, i, j + 1, currDis + 1, minDis);

    // grid[i][j]
}