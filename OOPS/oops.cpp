#include <bits/stdc++.h>

using namespace std;

class student {
    string name;

    public:
        int age;
        string gender;

        void setName (string n) {
            name = n;
        }

        void getName () {
            cout << name << endl;
        }

        void printInfo () {
            cout << name << endl;
            cout << age << endl;
            cout << gender << endl;
        }
};

int main () {
    student a;

    string name;
    cin >> name;
    a.setName(name);
    
    cin >> a.age;
    cin >> a.gender;

    // a.getName();
    // cout << a.age << endl;
    // cout << a.gender << endl;

    a.printInfo();

    return 0;
}