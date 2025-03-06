#include <bits/stdc++.h>
using namespace std;


/*
 
    Look like Valid Parenthess.
    
    Using Stack keep push elements to back() if u find a greater element than 
    stack.top() ? make nextGreater[stack.top()].

    Using While Loop:
    see if the current element can be 
    NextGreater for all pervious elements or Not.

    if found a NextGreater for all elements Stack --> empty.
    if stack isn't Empty then NextGreater for all remaining elements --> -1.


    Example :
    --------
    nums = {2, 0, 1, 3, 5}.     
    2:
    
    |     |
    |  2  |
    -------

    0:
    if its greater map it if not move to next element but push current.

    |  0  |
    |  2  |
    -------
    
    1:
    1 is greater than 0 `stack.top()` so map it 
    NextGreater(0) == 1.
    
    |     |
    |  2  |
    -------
    but not greater than 2 so push it anyway.

    |  1  |
    |  2  |
    -------

    3:
    3 is greater than 1 and 2 both, `stack.top()` map it 
    NextGreater(1) == 3.
    NextGreater(2) == 3.
    and push the current 3.
    
    |     |
    |  3  |
    -------

    Since 3 only left and no elements after it so 
    
    NextGreater(2) == 3.
    NextGreater(0) == 1.
    NextGreater(3) = -1.
    NextGreater(1) == 3.

*/


class Solution {
public:
    stack<int> s;
    unordered_map<int,int> nextGreater;
    vector<int> nextGreaterElement(vector<int>& nums1, 
                                   vector<int>& nums2) {
        for(int x : nums2) {
            while (!s.empty() && s.top() < x) {
                nextGreater[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }

        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }

        vector<int> ans;
        for(int x : nums1) {
            ans.push_back(nextGreater[x]);
        }

        return ans;
    }
};

int main() {
    

    return 0;
}
