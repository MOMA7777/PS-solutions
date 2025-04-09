#include <bits/stdc++.h>
using namespace std;

/* Every Magazine letter exist in the RansomNote but not otherwise */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int f[128] = { 0 };

        for(char c : magazine) f[c-'a']++;
        for(char c : ransomNote) {
            --f[c-'a'];

            if (f[c-'a'] < 0) return false;
        }

        return true;
    }
};

int main() {
    string s = "pld", t = "piple";

    Solution sol;
    cout << sol.canConstruct(s, t) << endl;

    return 0;
}
