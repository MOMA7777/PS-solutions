//https://codeforces.com/contest/677/problem/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h, x = 0, sum = 0;
    cin >> n >> h;

    for(int i = 1; i <= n; i++) {
        cin >> x;

        if (x > h) sum += 2;
        else sum++;
    }
    
    cout << sum << endl;

    return 0;
}
