#include <bits/stdc++.h>
using namespace std;

/*

    Checking for Existance and Frequancy at Once:
    ---------------------------------------------

    insert().second => true, if not exist in the set before AND INSERT IT.

    seen --> at first checks if the element not exist if so insert it 
    and since there's and && expressoin the second cond skipped 

    so  Example : "A A A A"
    
    first iteration : seen.insert(A).second == true but
    [!true] = false and became if (false and ....) SKIPPED.

    seen     = {A};
    repeated = {};

    second iteration : seen.insert(A).second == false [!false] = true;
    repeated.insert(A).second == true;

    so if (true and true) WE GOT 'A'

    third iteration : seen.insert(A).second == false -> true and repeated.insert(A).second -> false
    if (true and false) ........

    A WONT INSERT IN THE ANSWAR AGAIN......


*/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_set<string> seen, repeated;

        for(int i = 0; i < s.size(); i++) {
            string sub = s.substr(i, 10);

            if (!seen.insert(sub).second && repeated.insert(sub).second) 
                ans.push_back(sub);
        }

        return ans;
    }
};

/*

 BAD RUN-TIME.

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        
        vector<string> ans;
        string result; 
    
        for(int i = 0; i < s.size(); i++) {
            
            if (i+10 <= s.size()) {
                result = s.substr(i, 10);
    
                if ( mp.count(result) ) {
                    if (mp[result] == 1) ans.push_back(result), mp[result] = -1;
                }
                else {
                    mp[result] = 1;
                }
            }
    
        }
    
        return ans;
    }
};

*/

int main() {
    vector<string> ans;
    string s = "AAAAAAAAAAAAA";

    Solution sol;
    ans = sol.findRepeatedDnaSequences(s);

    for(string & str : ans) cout << str << endl;

    return 0;
}
