//problem link : https://codeforces.com/contest/1/problem/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, m, a;
    cin >> n >> m >> a;
    
    cout << (ll)(ceil((double)m / (double)a) * ceil((double)n / (double)a)) << endl;

    return 0;
}
