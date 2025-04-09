#include <bits/stdc++.h>
using namespace std;


/*

   Sorting for Counting Occurance of Elements :
   --------------------------------------------

   
    1- Since the old ways like :
        frequancy array consume --> O(n) space, Time O(n),
   
    2- Sorting will consume --> O(1) space, Time O(n).
        and it works for all frequancy methods and problems,'not just our case'.

*/


class Solution{
public:
    int majorityElement(vector<int>& nums) {
        int freq = 1, n = nums.size(), ans = -1;
        if (n == 1) return nums[0];
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i+1]) { 
                ++freq;
                if (freq > (int)(n/2)) ans = nums[i]; 
            }
            else freq = 1;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};

    Solution sol;
    cout << sol.majorityElement(nums) << endl;

        
    return 0;
}
