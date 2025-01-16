#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) { puts("YES"); return 0; } 
    
    char a[n][n];
    set<char> diagonals, normal;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        
            if (i == j || i + j == n - 1) diagonals.insert(a[i][j]);
            else                          normal   .insert(a[i][j]);
        }
    }

    if (  diagonals.size() == 1
      &&  normal   .size() == 1
      && *diagonals.begin() != *normal.begin() ) puts("YES");
    else                                         puts("NO");

    return 0;
}
