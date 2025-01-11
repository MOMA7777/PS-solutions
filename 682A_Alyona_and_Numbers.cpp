//problem link : https://codeforces.com/contest/682/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m;
    cin >> n >> m;

    ll cnt_n[5] = {0}, cnt_m[5] = {0};

    for(int i = 1; i <= 5; i++) {
        cnt_n[i % 5] += (n / 5) + (i <= (n % 5));
        cnt_m[i % 5] += (m / 5) + (i <= (m % 5));
    }
    
    ll zeros  = cnt_n[0] * cnt_m[0];
    ll ones   = cnt_n[1] * cnt_m[4];
    ll twos   = cnt_n[2] * cnt_m[3];
    ll thirds = cnt_n[3] * cnt_m[2];
    ll fours  = cnt_n[4] * cnt_m[1];

    cout << (ll)(zeros + ones + twos + thirds + fours) << endl;

    return 0;
}

