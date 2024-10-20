//https://codeforces.com/contest/782/problem/A

#include <bits/stdc++.h>
using namespace std;


int main () {
    
    int n; cin >> n;

    vector<int> v(n * 2);
    vector<int> freq(n * 100, 0);


    for (int i = 0; i < v.size(); i++) cin >> v[i];

    int cnt = 0, mx = -9999;
    for (int i = 0; i < v.size(); i++) {

        if ( freq[v[i]] ) { cnt--; }
        else {
            freq[v[i]] = 1;
            cnt++;
        }

        if ( cnt > mx ) mx = cnt;
    }

    cout << mx << endl;

    return 0;
}
