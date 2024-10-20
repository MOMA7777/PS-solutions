#include <iostream>
using namespace std;

char grid[10][10];
char ans[10]; 
char letters[] = {'@', 'I', 'E', 'H', 'O', 'V', 'A', '#'};
int indx, n, m;

//forth right left
int   dx[] =  {-1, 0, 0};
int   dy[] =  {0, 1, -1};
char dir[] =  {'f', 'r', 'l'};

void dfs(int x, int y, int indx) {
    if ( !((x >= 0 && x < n) && (y >= 0 && y < m)) ) return;
    if (letters[indx] != grid[x][y]) return;
    

    if (grid[x][y] == '#') {
        for (int i = 0; i < indx; i++) {
            if (i) printf(" ");

            if (ans[i] == 'f') printf("forth");
            else if (ans[i] == 'r') printf("right");
            else printf("left");
        }
        printf("\n");
        return;
    }


    for (int i = 0; i < 3; i++) {
        int xp = x + dx[i];
        int yp = y + dy[i];

        ans[indx] = dir[i];
        dfs(xp, yp, indx+1);
    }
}

int main() {
    int t; cin >> t;

    while (t--) {

        cin >> n >> m;
        
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') dfs(i, j, 0);
            }
        }
    }
    return 0;
}
