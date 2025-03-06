#include <bits/stdc++.h>
using namespace std;


/*
 
    Permutation turn to its base shape
    -----------------------------------
    any permuation in the world if u keep shifting
    it `its size()` times will turn on to it's basic
    shape.

    123, size = 3.
    first  : 231
    second : 312
    third  : 123
    
    we can exploit that by 
    seeing if the current permutation after rotating its `size()` 
    
    and not getting us the same type of sandwich 
    means it never contain that type and hence go to ENDLESS CYCLE.

    ---------------------EXAMPLE----------------------------------
    student  = 111
    sandwich = 011 

    means student should be shift until get 0
    after shifting 3 times 
    also not get 0 means so it will never and hence:

    you have 3 hungry students.

*/


class Solution {
public:
    queue<int> q;
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int &x : students) q.push(x);

        int count = 0, i = 0;
        while (!q.empty() && count != q.size()) {
            if (q.front() == sandwiches[i]) {
                count = 0, q.pop(), i++;
            }
            else {
                count++, q.push(q.front()), q.pop();
            }
        }

        return q.size();
    }
};



/* every one should finish the type of the sandwich first. */
//class Solution {
//public:
//    int countStudents(vector<int>& students, vector<int>& sandwiches) {
//        int z = 0, one = 0, hungry = students.size(); 
//        for(int& x : students) {
//            if (x == 0) z++;
//            else        one++;
//        }
//
//        for(int& x : sandwiches) {
//            if (x == 0) {
//                if (z == 0) return hungry;
//                else --z, --hungry;
//            }
//            else {
//                if (one == 0) return hungry;
//                else --one, --hungry;
//            }
//        }
//
//        return hungry;
//    }
//};

int main() {
    vector<int> s = {1,1,1,0,0,1}, d = {1,0,0,0,1,1};

    Solution sol;
    cout << sol.countStudents(s, d) << endl;

    return 0;
}
