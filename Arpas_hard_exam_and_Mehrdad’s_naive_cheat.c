//problem link : https://codeforces.com/problemset/problem/742/A

#include <stdio.h>
#include <math.h>
#define ll long long
int main() {
    ll n, x = 1378, count_x[5] = {0};
    
    for(int i = 1; i <= 4; i++) {
        count_x[i % 4] = x % 10;
        x *= 1378;
    }

    scanf("%lld", &n);
    
    if (n == 0) { puts("1"); return 0; }
    else {
        n %= 4;
        printf("%lld\n", count_x[n]);
    }

    return 0;
}
