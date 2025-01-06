//problem link : https://codeforces.com/contest/1204/problem/A

#include<bits/stdc++.h>
using namespace std;

// how much of something exist in Quantity ? 
// every binary number consist on bit set --> power of 2.
// half of power of 2's --> power of 4.

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }

    if ( sum == 1 ) cout << n / 2 << endl;
    else if ( sum > 1) {
        cout << (n + 1) / 2 << endl;
    }


    return 0;
}
