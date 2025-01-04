//problem link : https://codeforces.com/contest/165/problem/B

#include <bits/stdc++.h>
using namespace std;

bool canGet(int n, int k, int v) {
    int lines = 0, current = v;

    while ( current > 0 ) {
        lines += current;
        current /= k;
    }

    return lines >= n;
}

int main() {
    
    int n, k;
    cin >> n >> k;

    int l = 1, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;

        if ( canGet(n, k, m) ) {
            r = m;
        }
        else 
            l = m + 1;
    }

    cout << l << endl;

    return 0;
}

