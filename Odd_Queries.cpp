//link : https://codeforces.com/problemset/problem/1807/D

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
 *  Small part of Pic affec the Overall
 *
 *  how to calculate parts of arr,list without the other ?
 *  
 *  prefix sum array
 *  +
 *  divide the array into subarrays
 *
 *  then u can calculate any subarray 
 *  ------------------------------------------
 *
 *  if u have [l,r] interval ?
 *  before l ==>  prefix[l-1].
 *  after r  ==>  prefix[n] - prefix[r].
 *
 * */

int main() {
    int t; cin >> t;

    while (t--) {
        ll n, q;
        cin >> n >> q;
    
        ll a[n+2], pre[n+2];
    
        pre[0] = 0;
        for(ll i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        
        for(ll i = 1; i <= q; i++) {
            ll l, r, k;
            cin >> l >> r >> k;
    
            ll ans = (pre[l-1]) + (pre[n] - pre[r]) + (r-l+1) * k;
    
            if (ans % 2 != 0) cout << "YES" << endl;
            else              cout << "NO"  << endl;
        }
    }
    return 0;
}
