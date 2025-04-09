#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void convertString(string & s) {
        long long d = 0, f[128] = { 0 };
        
        for(int i = 0; i < s.size(); i++) {
            if (f[s[i]]) s[i] = (f[s[i]] + '0');
            else ++d, f[s[i]] = d, s[i] = d + '0';
        }
    }

    bool isIsomorphic(string s, string t) {
        convertString(s), convertString(t);

        return (s == t);
    }
};


int main() {
    string s = "egg", t = "bar";

    Solution sol;
    cout << sol.isIsomorphic(s, t) << endl;

    return 0;
}
