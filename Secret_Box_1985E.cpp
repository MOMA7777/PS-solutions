//problem link : https://codeforces.com/contest/1985/problem/E

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        ll x, y, z;
        ll a, b, c;
        ll mx_placments = 0, k;
    
        cin >> x >> y >> z >> k;
         
        for (a = 1; a <= x; a++) {
            if (k % a != 0) continue;
    
            for (b = 1; b <= y; b++) {
                if (k % (a * b) != 0) continue;
                
                c = k / (a * b);
    
                mx_placments = max(mx_placments, (x - a+1) * (y - b+1) * (z - c+1));
            }
        } 
        printf("%lld\n", mx_placments);
    }

    return 0;
}
