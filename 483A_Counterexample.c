//problem link : https://codeforces.com/contest/483/problem/A

#include <stdio.h>
#define ll long long

ll GCD(ll a, ll b) {
    ll mx = (a > b) ? a : b;
    ll mn = (a > b) ? b : a;

    int i = 9;
    while (i) {
        if (mx % i == 0 && mn % i == 0 && mx != i) {
            return i;
        }
        --i;
    }

    return 0;
}

int main() {

    ll l, r;
    scanf("%lld %lld", &l, &r);

    for(ll i = l; i <= r; i++) {
        for(ll j = i+1; j <= r; j++) {
            for(ll k = i+1; k < j; k++) {
                if ( GCD(i, k) == 1 && GCD(k, j) == 1 && GCD(i, j) != 1) 
                {
                    printf("%lld %lld %lld\n", i, k, j);
                    return 0;
                }
            }
        }
    }
    
    puts("-1");


    return 0;
}
