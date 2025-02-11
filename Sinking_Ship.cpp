//problem link : https://codeforces.com/problemset/problem/63/A

#include <bits/stdc++.h>
using namespace std;

/*
 *  unordered map dont gurantee ordering "Mazen 2025"
 *  
 *  How to sort elements based on your priorites ? give them hashes. 
 *
 *  rats            0
 *  women/children  1
 *  men             2
 *  captin          3
 *
 * */

int main() {
    map<int, vector<string>> evac; 

    int n; 
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        if      (s2 == "rat")                       { evac[1].push_back(s1); }
        else if (s2 == "woman" || s2 == "child") { evac[2].push_back(s1); }
        else if (s2 == "man")                       { evac[3].push_back(s1); }
        else                                        { evac[4].push_back(s1); }
    }
    
    for(const auto & key : evac) {
        for(const auto & name : key.second) {
            cout << name << endl;
        }
    }

    return 0;
}
