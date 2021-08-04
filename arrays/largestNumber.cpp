#include <bits/stdc++.h>

using namespace std;

bool myCompare (int a, int b) {
    string X = to_string(a);
    string Y = to_string(b);

    string XY = X + Y;
    string YX = Y + X;

    return (XY > YX);
}


int main () {
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), myCompare);

    if (A[0] == 0)
        return 0;

    string res;
    for (int a : A) {
        res += to_string(a);
    }
    cout << res << endl;

    return 0;
}