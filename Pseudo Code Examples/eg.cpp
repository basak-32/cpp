#include<bits/stdc++.h>

using namespace std;

class A {
    public:
        A() {
            cout << "C" << endl;
        }

        ~A() {
            cout << "D" << endl;
        }
};

int main () {
    // A a;
    // // delete[] a;

    int x = 0, y = x--/--x;

    cout << x << endl << y;

    return 0;
}