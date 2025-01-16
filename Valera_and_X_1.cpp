//problem link : https://codeforces.com/contest/404/problem/A

#include <bits/stdc++.h>
using namespace std;

//brute force solution.

bool check(char a[501][501], int s) {
    bool flag = 1;
    char diagonal = a[0][0], rest = a[0][1];

    if (diagonal == rest) { flag = false; return flag; } 

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {

            if (i == j || i + j == s-1) {
                if (a[i][j] != diagonal) { flag = false; break; } 
            }
            else { 
                if (a[i][j] != rest) { flag = false; break; } 
            }
        
        }
    }

    return flag;
}

int main() {
    int s;
    scanf("%d", &s);

    if (s == 1) { puts("YES"); return 0; } 

    char a[501][501];
    for (int i = 0; i < s; i++) {
        scanf("%s", a[i]);
    }

    bool res = check(a, s);

    if (res) puts("YES"); 
    else     puts("NO");
    
    return 0;
}
