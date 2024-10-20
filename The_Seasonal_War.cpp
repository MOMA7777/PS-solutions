//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=288

#include <bits/stdc++.h>
#define x first 
#define y second
using namespace std;
           // down  up   right   left   downRight     downleft      upRight    upLeft
int dir_r[] = {1,   -1,  0,      0,     1,            1,           -1,         -1};
int dir_c[] = {0,    0,  1,     -1,     1,           -1,            1,         -1};

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

unordered_set<pair<int,int>, PairHash> vis;


bool isWalkable(int x, int y, vector<vector<int>> &grid, int &sz) {
    bool boundry = (x >= 0 && x < sz) && (y >= 0 && y < sz);
    bool notVisited = (vis.find( {x, y} ) == vis.end());
    //imagine -1, 0 how to represent it ??
//    bool countable = (grid[x][y] == 1);

    return (boundry && notVisited);
}

void dfs(int x, int y, vector<vector<int>> &grid, int &sz) {
        vis.insert( {x, y} );
        
        for (int i = 0; i < 8; i++) {
            int nxt_r = dir_r[i] + x;
            int nxt_c = dir_c[i] + y;
    
            if ( isWalkable(nxt_r, nxt_c, grid, sz) ) {
                if (grid[nxt_r][nxt_c]) dfs(nxt_r, nxt_c, grid, sz);
            }
        }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream inputfile  ("input.txt");
    ofstream outputFile ("output.txt"); 
    
    if (!inputfile.is_open() || !outputFile.is_open()) {
        cerr << "couldn't open file\n";
    }

    int cnt = 0;
    int sz;
    while ( cin >> sz ) {
        cin.ignore();

        cnt++;
        int warEagle = 0;
        vector<vector<int>> grid(sz, vector<int>(sz, 0));
        vis.clear();

        string s;
        for(int i = 0; i < sz; i++) {

            getline(cin, s);
            for(int j = 0; j < sz; j++) {
                grid[i][j] = s[j] - '0';
            }
        }
   
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                if (grid[i][j] && vis.find({i,j}) == vis.end() ) {
                    dfs(i, j, grid, sz);
                    warEagle++;
                }
            }
        }

        cout << "Image number " << cnt << " contains " << warEagle << " war eagles.\n";
        
    }

    return 0;
}
