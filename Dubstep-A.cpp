#include <bits/stdc++.h>
using namespace std;

/*
 *  iteration varibale in for loop can be like while loop 
 *  and Goes for infinity.
 *
 *  last char in string is '\0' so no out of boudry in s[i],s[i+1].
 *
 * */

int main() {
    string s, ans; cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i += 2;

            if (ans.size() > 0) ans.push_back(' ');
        } else {
            ans.push_back(s[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == ' ' && ans[i+1] == ' ') continue;

        cout << ans[i];
    }
    cout << endl;

    return 0;
}
