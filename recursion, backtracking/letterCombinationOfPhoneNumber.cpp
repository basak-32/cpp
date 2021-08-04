#include <bits/stdc++.h>

using namespace std;

void recurse (vector<string> &res, string digits, string curr, int index, vector<string> mapping);

int main () {
    string digits;
    cin >> digits;

    vector<string> res;
      
    // if (digits.length() == 0)
      
    // }
  
    vector<string> mapping = {
      "0",
      "1",
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz"
    };
    
    recurse(res, digits, "", 0, mapping);
  
    for (auto str : res) {
        cout << str << endl;
    }
}


void recurse (vector<string> &res, string digits, string curr, int index, vector<string> mapping) {
    if (index == digits.length()) {
        res.push_back(curr);
        return;
    }
      
    string letters = mapping[digits[index] - '0'];
    for (char ch : letters) {
    recurse(res, digits, curr + ch, index + 1, mapping);
    }
}