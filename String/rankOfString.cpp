#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<string> str;

    for (int i = 0; i < n; i++) {
        string curr = "";
        for (int j = i; j < n; j++) {
            curr += s[j];
            str.push_back(curr);
        }
    }

    string temp;

    for(int i = 0; i < str.size() - 1; ++i)
       for( int j = i+1; j < str.size(); ++j)
       {
          if(str[i] > str[j])
          {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
          }
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == s)
            cout << i+1;
            // return i + 1;
    }
}