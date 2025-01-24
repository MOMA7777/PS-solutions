#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        ll n, d; 
        cin >> n >> d;
                                                             cout <<  "1";
        if ( n >= 3  || d % 3 == 0)                          cout << " 3";
        if (            d % 5 == 0)                          cout << " 5";
        if ( n >= 3 ||  d % 7 == 0)                          cout << " 7";
        if ((n >= 3 &&  d % 3 == 0) || n >= 6 || d % 9 == 0) cout << " 9";
    
        cout << endl;
    }

    return 0;
}
