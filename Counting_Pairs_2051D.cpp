#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        
        int a[300030];
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        
        sort(a + 1, a + n + 1);
        
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = lower_bound(a + 1, a + n + 1, sum - a[i] - y) - a;
            int r = upper_bound(a + 1, a + n + 1, sum - a[i] - x) - a - 1;
            
            l = max(l, i + 1);
            ans += max(r - l + 1, 0);
        }
        
        cout << ans << endl;
    }
   
    return 0;
}
