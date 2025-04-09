#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string stck;
    
        for(int i = 0; i < s.size(); i++) {
            if (!stck.empty()) {
                if (stck.back() == s[i]) { stck.pop_back(); continue; }
            }

            stck.push_back(s[i]);
        }

        return stck;
    }
};


int main() {
    Solution sol;

    cout << sol.removeDuplicates("azxxzy") << endl;

    return 0;
}
