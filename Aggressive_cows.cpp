//problem link : https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;

bool feasible(vector<int> & stalls, int N, int C, int distance) {
    int placed = 1; //we place the first cow in the stall[0]
    int last_pos = stalls[0];

    for (int i = 1; i < N; i++) {
        if ( stalls[i] - last_pos >= distance ) {
            last_pos = stalls[i];
            placed++;

            if (placed == C) return true;
        }
    }

    return false;
}

void bs(vector<int> & stalls, int & N, int & C) {
    int low = 1, high = stalls[N - 1] - stalls[0]; //distances not indexes
    int res = 0;

    while ( low <= high ) { //vs low < high ?? (bounding)
        int m = (low + high) / 2;

        if ( feasible(stalls, N, C, m) ) { 
            res = m;
            low = m + 1;
        }
        else 
            high = m - 1;
    }
    
    cout << res << endl;
}


int main() {
    vector<int> stalls;
    int N, c;

    int t;
    cin >> t;

    while (t--) {
        stalls.resize(0);
        cin >> N >> c;
    
        for(int i = 0; i < N; i++) {
            int x;
            cin >> x;
    
            stalls.push_back( x );
        }
    
        sort(stalls.begin(), stalls.end());
        bs(stalls, N, c);
    }
    return 0;
}

