#include <bits/stdc++.h>
using namespace std;

/*
    first occurance ==> negative.
    second occurance ==> positive.
    
    then exclude positives later...
    
    starting from 1-index to make difference when,
    oppose the sign, 1 -> -1, 0 -> -0 = 0 ....

Example:
-------    
    leetcode.    
    l --> -1
    e --> -2
    e --> 3
    t --> -4
    c --> -5
    o --> -6
    d --> -7
    e --> 8.

    exclude positives and oppose the sign for negative to get MIN == FIRST_ONE.
    l = 1, t = 4, c = 5, o = 6, d = 7.

    so its `L` == 1-1 = 0.

*/



class Solution {
    public:
    int firstUniqChar(string s) {
        int position[26] = {0};
        
        for(int i = 1; i <= s.size(); i++) {
            char c = s[i-1] - 'a';
            if (position[c] == 0) position[c] = -i;
            else                  position[c] = i;
        }

        int minVal = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if (position[i] < 0)
                minVal = min(minVal, -position[i]);
        }

        return minVal == INT_MAX ? -1 : minVal-1;
    }
};

int main() {
    string s = "loveleetcode";

    Solution sol;
    int ans = sol.firstUniqChar(s);
    cout << ans << endl;

    return 0;
}
