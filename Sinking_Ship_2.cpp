#include <bits/stdc++.h>
using namespace std;

/*
 *  exploiting the constrains : n <= 100
 *  
 *  means 400 iterations (wrost case).
 *
 * */

int main() {
    int n; 
    cin >> n;

    string s1[111], s2[111];
    for(int i = 1; i <= n; i++) 
        cin >> s1[i] >> s2[i];

    for(int i = 1; i <= n; i++) { //rats
        if (s2[i][0] == 'r') 
            cout << s1[i] << endl;
    }
    
    for(int i = 1; i <= n; i++) { //women, child
        if (s2[i][0] == 'w' || s2[i][1] == 'h') 
            cout << s1[i] << endl;
    }
    
    for(int i = 1; i <= n; i++) { //man
        if (s2[i][0] == 'm') 
            cout << s1[i] << endl;
    }

    for(int i = 1; i <= n; i++) { //cap
        if (s2[i][2] == 'p') 
            cout << s1[i] << endl;
    }

    return 0;
}

