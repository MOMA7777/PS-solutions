#include <bits/stdc++.h>
using namespace std;

/* 
    
   Nothing New
 
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();

        for (int i = 0; i < n-1; i++) 
            for (int j = i+1; j < n; j++) 
                if (prices[j] <= prices[i]) { 
                    prices[i] -= prices[j];
                    break;
                }

        return prices;
    }
};

int main() {
    Solution sol;

    vector<int> v = {10,1,1,6}, ans;
    ans = sol.finalPrices(v);

    for(auto &x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
