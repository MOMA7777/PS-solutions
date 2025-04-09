#include <bits/stdc++.h>
using namespace std;

/*

    Shrinking when met condition:
    -----------------------------
                0 1 2 3 4 5
    Example : " p w w k e w ".

    p -> r = 0, l = 0; '1'
    w -> r = 1, l = 0, '2'          0 to 1 pw
    w -> r = 2, l = 2, '1'
    k -> r = 3, l = 2, '2'          2 to 3 wk
    e -> r = 4, l = 2, '3'          2 to 4 wke
    w -> r = 5, l = 3, '3'          3 to 5 kew

 * */ 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int f[128] = {0};
        int l = 0, mx = 0;

        for(int r = 0; r < s.size(); r++) {
            ++f[s[r]];

            while (f[s[r]] > 1) --f[s[l]], ++l;

            mx = max(mx, r-l+1);
        }

        return mx;
    }
};

int main() {
    string s = "abcabcbb";

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
