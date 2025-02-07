//problem link : https://codeforces.com/contest/1916/problem/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
 *  if x a number and have g1, g2, g3, ..., gn greatest common divisors
 *
 *  g1, g2 was give.
 *
 *  if g1 mod g2 = 0.
 *
 *  then g2 = g1 * smallest prime factor to 'x'.
 *
 *  hence : smallest prime factor to x = g2 / g1.
 *
 *  x = g2 * smallest prime factor to x = g2 * (g2/g1).
 *
 *  but if g2 mod g1 != 0
 *
 *  then gcd(g1, g2) will play a role.
 *
 *  x = g1 * g2 / gcd(g1, g2); shit very complicated i know.
 *
 * */

int main() {
    int t; 
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;
    
        if (b % a == 0) {
            cout << b * (b / a) << endl;
        }
        else {
            cout << b * a / gcd(a,b) << endl;
        } 
    }

    return 0;
}
