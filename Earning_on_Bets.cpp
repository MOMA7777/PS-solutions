//problem link : https://codeforces.com/contest/1979/problem/C


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    const int BIG = 232792560; //lcm for 1 to 20 for avoiding percisions
    
    int t; 
    cin >> t;

    while (t--) {
        ll k[1234], x[1233], sum = 0, n = 0;
        cin >> n;
    
        for (int i = 1; i <= n; i++) cin >> k[i];
    
        for (int i = 1; i <= n; i++) {
            x[i] = BIG / k[i];
            sum += x[i];
        }

        if (sum >= BIG) { cout << "-1" << endl; }
        else {
            for (int i = 1; i <= n; i++) 
                cout << x[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
