//problem link : https://codeforces.com/problemset/problem/2039/C1

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t; cin >> t;

    while (t--) {
        ll x, r, cnt = 0;
        cin >> x >> r;
    
        for (int i = 1; i < x; i++) {
            int y = (x^i);
            
            if ((x % i == 0 || y % i == 0) && (y <= r && y >= 1)) cnt++;
        }
    
        cout << cnt << endl;
    }
    
    return 0;
}
