#include <bits/stdc++.h>
using namespace std;

/*

 O(n) time and O(n) space.


    if Stack = 1, 2, 3, 4.
    p1 = 4. poped
    p2 = 3. poped

    then to push them to stack first insert p2 `3` then p1 `4`.



    clean code adivces :
    --------------------
       1 line operatoins.
       2 isolating major operations from each other.
       3 make names Small and Unique.

*/

class Solution {
public:
    stack<int> N;
    
    int calPoints(vector<string>& operations) {
        for (auto & op : operations) {
            if (op == "+") {
                int p1 = N.top(); 
                N.pop();
                int p2 = N.top(); 
                N.pop();

                N.push(p2), N.push(p1), N.push(p1+p2);
            }

            else if (op == "D") {
                N.push(N.top() * 2);
            }

            else if (op == "C") {
                N.pop();
            }

            else {
                N.push(stoi(op));
            }
        }
   
        int sum = 0;
        while (!N.empty()) {
            sum += N.top(), N.pop();
        }

        return sum;
    }
};





int main() {
    vector<string> op = {"57","D","-3","-58","D","77","+","C","+","+","38","78","-6","24","-46","+","31","20","D","-81"};
    
    Solution sol;
    int ans = sol.calPoints(op);
    cout << ans << endl;

    return 0;
}
