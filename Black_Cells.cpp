//problem link : https://codeforces.com/problemset/problem/2026/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
    
        auto check = [&](ll mid) -> bool {
            int skip = 0;
            for (int i = 1; i <= n; i++) {
                if (i == n) {
                    if (skip) return false;
                } else if (a[i + 1] - a[i] > mid) {
                    if (skip) return false;
                    skip = 1;
                } else {
                    i++;
                }
            }
            return true;
        };
    
        ll left = 1, right = 1e18;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << left << '\n';
    }

    return 0;
}
