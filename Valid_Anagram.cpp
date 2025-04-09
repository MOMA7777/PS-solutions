#include <bits/stdc++.h>
using namespace std;

/*

    SORTING     O(N LOGN):
    -------

    sorting solving the problem of Checking 
    1- Existance of Charactars.
    2- Their Number of Occurance.

    sorting solving this problem quiet effecient,
    [car, rac] ==> acr. 
    [anagram, nagaram] ==> aaagmnr.

-------------------------------------------------------
    
    BALANCING FREQUANCY ARRAY   O(N):
    -------------------------

    increasing and decreasing of frequancy array and
    initiating each char with 0, if it decreased then
    stop, 

    will help with determine the 2 existance, number of 
    occurance.... but in space o(n) extra.

 * */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> f(26, 0);
        for(char c : s) f[c - 'a']++;
        for(char c : t) {
            --f[c - 'a'];
            if (f[c] < 0) return false;
        }

        return true;
    }
};



int main() {
    string s, t;
    cin >> s >> t;

    Solution sol;
    cout << sol.isAnagram(s, t) << endl;

    return 0;
}
