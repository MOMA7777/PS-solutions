#include <stdio.h>
#define ll long long
int main() {

    ll x, cnt = 0;
    scanf("%lld", &x);

    while ( x != 0 ) {
        int m = x % 2;
        if ( m ) cnt++;

        x /= 2;
    }

    printf("%lld\n", cnt);

    return 0;
}
