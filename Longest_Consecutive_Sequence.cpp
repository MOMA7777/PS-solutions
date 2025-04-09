#include <bits/stdc++.h>
using namespace std;

/*
    The Hash_Set solve the two problems :
    1- duplicates.
    2- sorting.

*/


class Solution {
public:
    int longestConsecutive(vector<int> & nums) {
        set<int> st;
        
        for(auto &x : nums) st.insert(x);
    
        for(auto &x : st) cout << x << " ";
        cout << endl;
    
        int cnt = 1, mx = 1, len = st.size();
        vector<int> arr(st.begin(), st.end());
    
        for(int i = 1; i < len; i++) {
            if (arr[i] == arr[i-1] + 1) ++cnt;
            else cnt = 1;
            
            mx = max(mx, cnt);
        }
   
        return mx;
    }
};



int main() {
    vector<int> num = {9,1,4,7,3,-1,0,5,8,-1,6};
    set<int> st(num.begin(), num.end());

    for(auto &x : st) cout << x << " ";
    cout << endl;

    return 0;
}

