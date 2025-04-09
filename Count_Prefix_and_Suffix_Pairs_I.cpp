#include <bits/stdc++.h>
using namespace std;

// O(N^2 * M). its like three nasted loops!
class Solution {
private:
    bool isPrefixAndSuffix(string & s, string & t) {
        if (s.size() > t.size()) return false;

        return (t.starts_with(s) && t.ends_with(s));
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if ( isPrefixAndSuffix(words[i], words[j]) ) ++cnt;
            }
        } 

        return cnt;
    }
};

int main() {
    vector<string> w = {"abab","ab"};
    
    Solution sol;
    cout << sol.countPrefixSuffixPairs(w) << endl;

    return 0;
}
