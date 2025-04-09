#include <bits/stdc++.h>
using namespace std;

/*


    Key Insights:
    -------------
    1-
    for any fixed pattern u want to group together
    Valid Choice ==> Map

    and take the fixed thing as key maps to all of them.

    for example : words after sorting gives same answar.
                  numbers give to same index....

    eat, tea, ate ==> ate.
    [ate] -> eat -> tea -> ate.


    2-
    Map to 2D matrix in CPP
    
    the dynamic loop skip the indexes directly 
    put u have to give to `.socend` to push the VALUES 
    in 2d matrix but the KEYS wont pushes just as indexes

    mp[1] = m, a, b;
    mp[2] = z;

    2d res = mp;
    
    res[0] = m, a, b.
    res[1] = z.

 * */


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for(string & s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            res[k].pushs;
        }

        vector<vector<string>> ans;
        for(auto & x : res) {
            ans.push_back(x.second);
        }

        return ans;
    }
};


int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> cpy = strs;

    for(string & s : cpy) sort(s.begin(), s.end());

    vector<vector<string>> v(10);
    for(int i = 0; i < cpy.size(); i++) {
        if (cpy[i] != ".") v[i].push_back(strs[i]);

        for(int j = i+1; j < strs.size(); j++) {
            if (cpy[j] != "." && cpy[j] == cpy[i]) { 
                v[i].push_back(strs[j]);  
                cpy[j] = ".";
            }
        }

        cpy[i] = ".";
    }

    for(int i = 0; i < 10; i++) {
        for(string & s: v[i]) cout << s << " " << i << endl;
        cout << endl;
    }

    return 0;
}
