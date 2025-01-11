//problem link : https://codeforces.com/contest/699/problem/A

#include <stdio.h>
#include <limits.h>
#define big INT_MAX
#define ll long long

int main() {
    ll n, st = 0, e = 0, mn = big;
    scanf("%lld", &n);

    char d[n+1];
    ll   s[n+1];

    scanf("%s", d);
    d[n] = '\0';

    for (int i = 0; i < n; i++) scanf("%lld", &s[i]);

    for (int i = 0; i < n; i++) {
        st = 0, e = 0;

        if ( d[i] == 'R' && i+1 < n) 
           if ( d[i+1] == 'L' ) {
                st = s[i], e = s[i+1];
                if (mn > (e-st)/2) mn = (e-st)/2;
           } 
    }

    if (mn == big) puts("-1");
    else         printf("%lld\n", mn);

    return 0;
}
