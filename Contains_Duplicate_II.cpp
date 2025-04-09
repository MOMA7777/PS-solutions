#include <bits/stdc++.h>
using namespace std;

/*

    Use Maps to Store Last Occurance and Compare with Current Occurance ==> distance.

 * */


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> lastSeen;

        for(int i = 0; i < nums.size(); i++) {
            if (lastSeen.count(nums[i]) && i - lastSeen[nums[i]] <= k) return true;
            
            lastSeen[nums[i]] = i;
        }

        return false;
    }
};


int main() {

    vector<int> a = {1,2,3,1,2,3};

    Solution s;
    cout << s.containsNearbyDuplicate(a, 2) << endl;


    return 0;
}
