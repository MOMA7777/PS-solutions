//problem link : https://codeforces.com/contest/289/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, x = 0, res = 0;
    cin >> n >> k;

    while (n--) {
        int l, r;
        cin >> l >> r;

        x += (max(l,r) - min(l,r)) + 1;
    }

    res = (k * ceil((double)x / (double)k)) - x;

    cout << res << endl;

    return 0;
}
