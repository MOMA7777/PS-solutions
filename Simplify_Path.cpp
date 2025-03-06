#include <bits/stdc++.h>
using namespace std;

/*

    Tokenization in cpp:
    --------------------

    abc//ee/../../fj/moma/8899/...
                
    into:

    [abc], [ee], [..], [..], [fj], [moma], [8899]

    1 - Stack.
        vector<string> stack.

    2 - token.
        string token.

    at each time u meet '/' ignore it and start new token
    aka : token.clear(), and concatnating by 
    token += current char.

    if current_token = .. ==> pop last token from the Stack.
    if current_token = .  ==> dont do any thing

    otherwise ==> push it to Stack.

 */

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stck;
        string token;
        int len = path.size()-1;

        for(int i = 0; i <= len; i++) {
            if (path[i] == '/') continue;

            token.clear();
            while (i <= len && path[i] != '/') {
                token += path[i];
                ++i;
            }

            if (token == ".") continue;
            else if (token == "..") {
                if (!stck.empty()) stck.pop_back();
            }
            else stck.push_back(token);
        }

        string result = "/";
        for(int i = 0; i < stck.size(); i++) {
            result += stck[i];
            if (i != stck.size()-1) result += "/";
        }

        return result;
    }
};


int main() {
    string str = "/../";
   
    Solution sol;

    cout << sol.simplifyPath(str) << endl;

    return 0;
}
