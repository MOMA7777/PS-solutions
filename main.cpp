#include <bits/stdc++.h>
//hello
#define x first
#define y second
using namespace std;


struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

unordered_map<pair<int,int>, pair<int,int>, PairHash> child; //cant be imagine parent[f] = f;
                                                             //that will go forever 
                                                            //it must be positioning parents
        
           //forth    right    left
int   dx[] = {-1 ,      0,      0};
int   dy[] = {0  ,      1,     -1};
char dir[] = {'f',    'r',    'l'};

map<int, vector<string>> mp;
//IEHOVA
set<char> letters = {'I', 'E', 'H', 'O', 'V', 'A'};

//is there's any better way to do path compression ?
//better than maping each neibour with its parent ?? 
//somethign like vector ?? but how to exclude wrong paths ?

//child-parent instead of parent-neibour ? avoid creating vector for backtracking paths.
void dfs (pair<int,int> pos, int &n, int &m, vector<vector<char>> &grid) {
    for (int i = 0; i < 3; i++) {
        int xp = dx[i] + pos.x;
        int yp = dy[i] + pos.y;
  
        if ( !(xp >= 0 && xp < n && yp >= 0 && yp < m) ) { continue; } 

        if ( grid[xp][yp] == '#' ) {
            grid[xp][yp] = dir[i];
            child[ {pos.x, pos.y} ] = {xp, yp};
            return;
        }

        if ( letters.find( grid[xp][yp] ) != letters.end() ) {
            grid[xp][yp] = dir[i];
            child[ {pos.x, pos.y} ] = {xp, yp};

            dfs ( {xp, yp}, n, m, grid );
        }
    } 

}

static int testCase = 1;

void solve () {


    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m,'.'));
    pair<int,int> startPos, endPos;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if ( grid[i][j] == '@' ) startPos.x = i, startPos.y = j;
            if ( grid[i][j] == '#' ) endPos.x = i, endPos.y = j; 
        }
    }

    dfs( {startPos.x, startPos.y}, n, m, grid );

    pair<int,int> p = startPos;
    while ( p != endPos ) {
        p = child[p];
        if      (grid[p.x][p.y] == 'f') mp[testCase].push_back("forth");
        else if (grid[p.x][p.y] == 'r') mp[testCase].push_back("right");
        else if (grid[p.x][p.y] == 'l') mp[testCase].push_back("left");
    }
    testCase++;
}

int main() {

    auto time1 = std::chrono::high_resolution_clock::now();

    int t; cin >> t;
    while (t--) solve();


    for (int i = 1; i <= testCase; i++) {
        for (auto & direction : mp[i]) {
           cout << direction << " "; 
        }
        cout << endl;
    } 
    
    auto time2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double, milli> totallTime = time2 - time1;

    cout << "\ntime : " << totallTime.count() << endl;
    return 0;
}
