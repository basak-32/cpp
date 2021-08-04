#include <bits/stdc++.h>

using namespace std;

int check (int a[3][3]) {
    int count = 0;
    
    
    if ((a[1][0] - a[1][1]) == (a[1][1] - a[1][2]))
        count++;

    if ((a[0][1] - a[1][1]) == (a[1][1] - a[2][1]))
        count++;
    
    if ((a[0][0] - a[1][1]) == (a[1][1] - a[2][2]))
        count++;
        
    if ((a[0][2] - a[1][1]) == (a[1][1] - a[2][0]))
        count++;
        
    return count;
}

int main () {
    int t;
    cin >> t;
    
    for (int round = 1; round <= t; round++) {
        int a[3][3];
        
        a[1][1] = 0;
        cin >> a[0][0] >> a[0][1] >> a[0][2];
        cin >> a[1][0] >> a[1][2];
        cin >> a[2][0] >> a[2][1] >> a[2][2];
        
        int maxCount = 0;
        int maxNo = INT_MIN, minNo = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                maxNo = max(maxNo, a[i][j]);
                minNo = min(minNo, a[i][j]);
            }
        }
        
        int baseCount = 0;
        if ((a[0][0] - a[0][1]) == (a[0][1] - a[0][2])) {
            baseCount++;
        }
        if ((a[2][0] - a[2][1]) == (a[2][1] - a[2][2])) {
            baseCount++;
        }
        if ((a[0][0] - a[1][0]) == (a[1][0] - a[2][0])) {
            baseCount++;
        }
        if ((a[0][2] - a[1][2]) == (a[1][2] - a[2][2])) {
            baseCount++;
        }
        
        int totalCount = 0;
        for (int i = minNo; i <= maxNo; i++) {
            int count = 0;
            a[1][1] = i;
            count = max(count, check(a));
            totalCount = baseCount + count;
            maxCount = max(maxCount, totalCount);
        }
        
        cout << "Case #" << round << ": " << maxCount << endl;
    }
    
    return 0;
}