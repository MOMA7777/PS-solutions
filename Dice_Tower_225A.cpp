//problem link : https://codeforces.com/problemset/problem/225/A

#include<bits/stdc++.h>
using namespace std;
int main() { 
    int n, a, b, top, bott, flag = 1;
    cin >> n;

    cin >> top;
    bott = 7-top;

    while (n--) {
        set<pair<int,int>> st;
        cin >> a >> b;
        int current_top, current_bott;

        if ( st.find({a, b}) != st.end() ) { puts("NO"); return 0; } 
        else { st.insert( {a, b} ); }

        for(int i = 1; i <= 6; i++) {
            if ( i == a || i == 7-a || i == b || i == 7-b ) continue;
            else { current_top = i, current_bott = 7-i; break; } 
        }
        
        if ((top == current_top || top == current_bott) && (bott == current_bott || bott == current_top)) flag = 1;
        else { flag = 0; break; } 
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;    
}
