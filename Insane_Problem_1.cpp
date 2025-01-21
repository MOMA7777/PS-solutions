//problem link : https://codeforces.com/contest/2044/problem/E

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
   
        ll p = 1, result = 0;
        while (true) {
            ll lowr_bound = max(l1, (l2 + p - 1) / p);
            ll uppr_bound = min(r1, r2 / p);
        
            if (lowr_bound <= uppr_bound) 
                result += (uppr_bound - lowr_bound) + 1;
        
            if (p > r2) break;
        
            p *= k;
        }
        cout << result << endl;
    }
    
    return 0;
}
