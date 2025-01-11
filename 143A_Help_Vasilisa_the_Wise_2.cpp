//problem link : https://codeforces.com/contest/143/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {

    int r1, r2, c1, c2, d1, d2;
    vector<int> gems(4);

    cin >> r1 >> r2;
    cin >> c1 >> c2;
    cin >> d1 >> d2;

    gems[0] = (r1 + c1 - d2) / 2;
    gems[1] = r1 - gems[0];
    gems[2] = c1 - gems[0];
    gems[3] = d1 - gems[0];

    if ( gems[1] != d2 - gems[2] || gems[1] != c2 - gems[3] ) { puts("-1"); return 0; } 
    if ( gems[2] != r2 - gems[3]) { puts("-1"); return 0; }

    for(int i = 0; i < gems.size(); i++) {
        if (gems[i] <= 0 || gems[i] > 9) { puts("-1"); return 0; }

        for(int j = 0; j < gems.size(); j++) {
            if (i == j) continue;

            if (gems[i] == gems[j]) { puts("-1"); return 0; } 
        }
    }

    cout << gems[0] << " " << gems[1] << endl;
    cout << gems[2] << " " << gems[3] << endl;

    return 0;
}
