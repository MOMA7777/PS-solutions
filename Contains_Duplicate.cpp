#include <bits/stdc++.h>
using namespace std;

/*

    Insertion Sort takes O(n^2) at worse case:
    ------------------------------------------
    insertion sort pattern ..

    4, 3, 2, 1.
    
    4, 4, 2, 1.
    3, 4, 2, 1.

    3, 4, 4, 1.
    3, 3, 4, 1.
    2, 3, 4, 1.

    2, 3, 4, 4.
    2, 3, 3, 4.
    2, 2, 3, 4.
    1, 2, 3, 4.

    final : 1 - 2 - 3 - 4.


*/

class Solution {
public:
    bool containsDuplicate(vector<int>& n) {
        int len = n.size();

        for(int i = 1; i < len; i++) {
            int j = i - 1, k = n[i];

            while (j >= 0 and n[j] > k) {
                n[j+1] = n[j];
                --j;
            } 

            n[j+1] = k;
            
            if (j >= 0 and n[j] == k) return true;
        }

        return false;
    }
};



int main() {
    vector<int> a = {1,2,3,4};

    Solution s;
    cout << s.containsDuplicate(a) << endl;



    return 0;
}
