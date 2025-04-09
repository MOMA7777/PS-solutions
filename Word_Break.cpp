#include <bits/stdc++.h>
using namespace std;

/*

    1- Circuts:
    ------------

    in AND-Expression if the first condition is check and it false 
    the second one never even goes for checking


    if ( cond1 && cond2[recursion]) cond1 --> false, cond2 --> never examine.


    2- Recursion After finish:
    --------------------------

    not becuase the recursion has return to the stack frame means all the stack
    frames should be retured only it retured to the stack it derived from
    
    a
    aa
    aaa yes | then check the Rest : aaaa ==> return false

    go back to the orginal one aaa and conitnue;

    aaaa
    aaaaa
    ......

*/


class Solution {
public:
    unordered_map<string, bool> memo; 

    bool wordBreakHelper(string s, unordered_set<string>& wordDict) {
        if (s.empty()) return true; 
        if (memo.count(s)) return memo[s]; 

        for (int i = 1; i <= s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (wordDict.count(left) && wordBreakHelper(right, wordDict)) {
                return memo[s] = true; 
            }
        }

        return memo[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, wordSet);
    }
};


int main() {
    string s = "aaaaaaa";
    vector<string> v = {"aaaa", "aaa"};


    Solution sol;
    cout << sol.wordBreak(s, v) << endl;

    return 0;
}
