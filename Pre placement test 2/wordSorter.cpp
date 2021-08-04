#include<bits/stdc++.h>

using namespace std;

int countVal (string s) {
    int ans = 0;
    for (auto ch : s)
        ans += (ch - 'A') + 1;
        
    return ans;
}

int main () {
    string s;
    getline(cin, s);
    
    vector<pair<int, string>> vec;
    string word = "";
    
    for (auto ch : s) {
        if (ch == ' ') {
            vec.push_back(make_pair(countVal(word), word));
            word = "";
        } else if (ch == '.' || ch == ',' || ch == '?' || ch =='!') {
            vec.push_back(make_pair(countVal(word), word));
            word = "";
        } else {
            word += ch;
        }
    }
    
    sort(vec.begin(), vec.end());
    
    for (auto a : vec)
        cout << a.second << endl;
  
    return 0;
}