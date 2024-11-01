//problem link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3104

#include <bits/stdc++.h>

#define FOR(i,n)  for(int i = 0; i < n; i++) 
#define FORN(i,n) for(int i = 1; i <= n; i++) 
#define vec vector<int>

using namespace std;

         // down  up  right  left  
int dx[] = {1,   -1,  0,      0};
int dy[] = {0,    0,  1,     -1};

char grid[100][100];
int n = 0, ships;

void dfs(int x, int y) {
    grid[x][y] = '.';
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ( !(nx >= 0 && nx < n && ny >= 0 && ny < n) ) continue;
        
        if (grid[nx][ny] != '.') dfs(nx, ny); 
    }     
}

int main() {
    int t; cin >> t;
    vec cases;

    FORN(i,t) {
        ships = 0;
        cin >> n;
        
        for(int i = 0; i < n; i++)
            scanf("%s", grid[i]);
    
        for(int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 'x') { 
                    dfs(i, j);
                    ships++;
                }
       
        cases.push_back(ships);
    }
   
    //Case 1: 2
    //Case 2: 1
    FOR(i,cases.size()) {
        cout << "Case " << i+1 << ": " << cases[i] << endl;
    }
    
    return 0;
}
