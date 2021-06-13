#include<bits/stdc++.h>

using namespace std;

void arrange(int a[], int n) {
    sort(a, a+n);
    
    int b[n];
    
    int x = (n-1)/2;
    
    int i = 1, j = 1;
    
    b[x] = a[0];
    
    for (i = 1; i <= x; i++) {
        b[x+i] = a[j++];
        b[x-i] = a[j++];
    }
    
    if (n % 2 == 0)
        b[x+i] = a[j];
        
    for (int a : b)
        cout << a;
}

int main() {
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    arrange(a, n);
}