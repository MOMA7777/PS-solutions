#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int split(int n) {
        int ans = 0;
        
        while (n != 0) {
            ans += (int)pow(n % 10, 2); 
            n /= 10;
        }

        return ans;
    } 
    
    bool isHappy(int n) {
        map<int,int> mp;

        while (n != 1) {
            if (mp[n]) return false; 

            mp[n] = 1;
            n = split(n);
        }

        return true;
    }
};

int main() {
    int n = 9;

    for(int i = 1; i <= 200; i++) {
        n = split(n);

        if (n == 1) cout << "GOT IT\n";
        cout << n << endl;
    }

    return 0;
}
