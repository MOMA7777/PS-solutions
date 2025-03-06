#include <bits/stdc++.h>
using namespace std;

/*
    with vs without {} : 
    --------------------
    if (cond1) 
        if (cond2) 
    else     
    -Here else will interpred as `if(cond2)` one.

    if (cond1) {
        if (cond2)
    }
    else     
    - Here else will interpred as `if(cond1)` one.

    The Solution is about Counting number of Skips and Comparing
    each charactar:
    ------------------------------------------------------------

    s --> a b # c
    t --> a d # c
    
    for each string be have 1 iterator and 1 skipper.
    if i u found `#` skipper will increase 
    but if u found normal charactar :
        u check weither this charactar was suppose to delete by backspace or not.
        and by ==> skipper.

        if skipper is positive aka : u found `skipper` number of #
        then do not even compare this charactar and move to next one,
        until `skiper == 0` now skip chars has finished.

   ------------------------ EXAMPLE ----------------------------------
    s = a b # c.
    t = a d # c.
    
    c with c  
    both dont equal # char and hence no skipper yet.
    move...

    # in s and # in t   
    so for s and t we have 1 skipper 
    move...

    `b` in s and `d`   
    in t but since we have 1 skipper we wont compare those
    leave them becuase they will delete by # char anyway so NOW `skipper = 0`.
    move...

    `a` in s and `a` in t
    both are equal the both strings are finshed so yeah both are equal.

 * */


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        int skip_s = 0, skip_t = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') skip_s++, --i;
                else if (skip_s > 0) --skip_s, --i;
                else break;
            }

            while (j >= 0) {
                if (t[j] == '#') skip_t++, --j;
                else if (skip_t > 0) --skip_t, --j;
                else break;
            }

            if ((i >= 0 && j >= 0) && s[i] != t[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;

            --i, --j;
        }

        return true;
    }
};

int main() {
    string s = "ab#c", t = "ad#c";

    Solution sol;
    bool ans = sol.backspaceCompare(s, t);
    cout << ans << endl;

    return 0;
}



// O(n) time, O(n) space.
//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//        vector<char> ss, tt;
//
//        for(char c : s) {
//            if (c == '#') {
//                if (!ss.empty()) ss.pop_back();
//            }
//            else ss.push_back(c);
//        }
//        
//        for(char c : t) {
//            if (c == '#') {
//                if (!tt.empty()) tt.pop_back();
//            }
//            else tt.push_back(c);
//        }
// 
//        return ss == tt;
//    }
//};
//

