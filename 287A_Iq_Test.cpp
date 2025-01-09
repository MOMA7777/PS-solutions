#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[4][4];

    for (int i = 0; i < 4; i++) 
        scanf("%s", a[i]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int black = 0, white = 0; //per cell

            black = (a[i][j] == '#') + (a[i][j+1] == '#') + (a[i+1][j] == '#') + (a[i+1][j+1] == '#');
            white = 4 - black;

            if (black >= 3 || white >= 3) { puts("YES"); return 0; }
        }
    }

    puts("NO");

    return 0;
}
