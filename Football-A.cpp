#include <bits/stdc++.h>
using namespace std;

/* 
 *  Enumeration:
 *  ------------
 *
 *  if S[i] = something -> increasment
 *  if S[i] = S[i-1] or S[i] = S[i+1] -> increasment - 1.
 * 
 * */

int main() {
    string s; cin >> s;
    int len = s.size(), i = 0, cnt = 0;

    while (i < len) { 
        char c = s[i];
        cnt = 0;

        while (s[i] == c) ++cnt, ++i;

        if (cnt >= 7) { cout << "YES\n"; return 0; }
    }

    cout << "NO\n";

    return 0;
}
