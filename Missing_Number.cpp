#include <bits/stdc++.h>
using namespace std;

/*
 *
 *  TAKING THE CUMMULATIVE, and Substracting untill getting the lost number :-
 *  --------------------------------------------------------------------------
 *
 *
 *
 *  [0, 1, 3] size : 3
 *  
 *  means it should be 0, 1, 2, 3: cummulative is (3 * 4 / 2) = 6
 *  6 - 0 = 6.
 *  6 - 1 = 5.
 *  5 - 3 = 2.
 *
 *  Cummulative is : 2 (the answar aka: the missing).
 
 * */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();

        int c = len * (len+1) / 2;

        for(int i = 0; i < len; i++) {
            c -= nums[i];
        }

        return c;
    }
};



int main() {
    vector<int> ans = {9,6,4,2,3,5,7,0,1};

    Solution s;
    cout << s.missingNumber(ans) << endl;

    return 0;
}
