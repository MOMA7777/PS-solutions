//https://codeforces.com/problemset/problem/546/C

#include <bits/stdc++.h>
using namespace std;
#define MAX INT_MAX 
#define ll long long


string   Hash( deque<int> & dq1, deque<int> & dq2 );
void     Play( deque<int> & dq1, deque<int> & dq2 );

int main() {
    
    int rounds = 0;
    deque<int> dq1, dq2;
    map<string, int> hased_before;
    
    int n, k1, k2;
    cin >> n;

    cin >> k1;
    while ( k1-- ) {
        int x;
        cin >> x;
        dq1.push_back(x);
    }

    cin >> k2;
    while ( k2-- ) {
        int x;
        cin >> x;
        dq2.push_back(x);
    }

    //saving the game status and elements using hash algorithm
    //and if the hash key occurs only one time again
    //means the game will go infinity.
    while ( dq1.size() != 0 && dq2.size() != 0 ) {
        
        string x = Hash( dq1, dq2 );

        if ( hased_before[x] ) {
            cout << -1 << endl;
            return 0;
        } 
        else hased_before[x] = 1;
        
        Play( dq1, dq2 );
        
        rounds++;
    } 
    
    if ( dq1.size() == 0 ) {
        cout << rounds << ' ' <<  2 << endl;
    } else cout << rounds << ' ' << 1 << endl;

    return 0;
}

//hashing using concatnating-sequence.
string Hash( deque<int> & dq1, deque<int> & dq2 ) {

    string hashing = "";
    
    for (auto & tmp : dq1) hashing += (char)(tmp + '0');
    hashing += "0";
    for (auto & tmp : dq2) hashing += (char)(tmp + '0');

    return hashing;
}


//simulate the game.
void Play ( deque<int> & dq1, deque<int> & dq2 ) {
    
    int d1_top = dq1.front(); 
    int d2_top = dq2.front(); 
    
    if ( d1_top > d2_top ) {
        dq1.push_back( d2_top );
        dq1.push_back( d1_top );
        
        dq1.pop_front();
        dq2.pop_front();
    
    }
    else {
        dq2.push_back( d1_top );
        dq2.push_back( d2_top );
        
        dq1.pop_front();
        dq2.pop_front();
    }
}
