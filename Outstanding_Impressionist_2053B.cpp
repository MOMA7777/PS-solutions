#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; 
    cin >> t;


    while ( t-- ) {
        int n;
        cin >> n;

        vector<int> prefix(2*n + 1, 0), cnt(2*n + 1, 0), r(2*n+1, 0), l(2*n+1, 0);

        for(int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
    
            if (l[i] == r[i]) cnt[l[i]]++;
        }
    
        for(int i = 1; i <= 2 * n; i++) {
            prefix[i] = prefix[i-1] + (cnt[i] > 0);
        }
    
        for(int i = 1; i <= n; i++) {
            if (prefix[r[i]] - prefix[l[i] - 1] - (l[i]== r[i] && cnt[l[i]] == 1) == (r[i] - l[i] + 1)) 
                cout << "0";
            else 
                cout << "1";
        }
    
        cout << endl;
    }
    return 0;
}

