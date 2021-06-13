#include<bits/stdc++.h>

using namespace std;

int convert(int n);

int main() {
    int n, p;
    cin >> n >> p;
    
    int a[n], r[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (p == 0)
                res = 0;
            else
                res = a[n-1];
        } else
            res = a[i-1];
            
        res = (res * 10) + a[i];
        
        if (i == n-1) {
            if (p == 0)
                res = (res * 10) + 0;
            else
                res = (res * 10) + a[0];
        } else
            res = (res * 10) + a[i+1];
            
        r[i] = convert(res);
    }
    
    for (int i = 0; i < n; i++) {
        if (i == n-1)
            cout << r[i];
        else
            cout << r[i] << " ";
    }
}


int convert (int n) {
    int k = 0, ans = 0;
    while (n > 0) {
        int rem = n % 10;
        ans = ans + (rem << k);
        n = n / 10;
        k++;
    }
    
    return ans;
}