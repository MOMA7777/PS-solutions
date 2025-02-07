//problem link : https://codeforces.com/contest/1203/problem/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
 *  1- gcd ==> number of divisors
 *  2- how to get gcd of array ? 
 *  3- sqrt prevent pairs
 *
 *  1 : 
 *  gcd contain sqrt(g) number of divisors
 *  but only distinct pairs
 *
 *  2 : 
 *  gcd(a, 0) = a.
 *  iterative gcd(old, new) or gcd(a[i], a[i-1]) 
 *
 *  3 : 
 *  every x divide n
 *  then [x, n/x] divisors of n
 *      
 *  to not pairs like (5,5) or (6,6)
 *  just if n/x != x
 *
 *  (1,6)  _ 36/1 != 1.
 *  (2,18) _ 36/2 != 2. 
 *  (6,6)  _ 36/6 == 6.
 *
 * */


int main() {
    ll s, cnt = 0;
    cin >> s;

    ll g = 0; //not 1
    for(int i = 1; i <= s; i++) {
        ll x;
        cin >> x;

        g = gcd(g, x);
    }

    for (ll i = 1; i * i <= g; i++) {
        if (g % i == 0) { 
            cnt++;
            if (g / i != i) cnt++;
        }

    }

    cout << cnt << endl;

    return 0;
}
