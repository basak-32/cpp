#include <bits/stdc++.h>

using namespace std;

int main () {
    int A;
    cin >> A;

    string code = "ABCDEFGHIJKLMNOPQRSTUVWZYZ";
    string s = "";

    while (A > 0) {
        int digit = A % 26;
        char s1 = code[digit - 1];
        s = s1 + s;
        A /= 26;
    }

    cout << s << endl;

    return 0;
}