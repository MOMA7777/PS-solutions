#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>>     g;
vector<int>                        vis(101, 0);
int                                bench = 0;

bool dfs(int i, int parent, int odd_cycle) {
    vis[i] = 1;

    for (auto neibour : g[i]) {
        if ( !vis[neibour] ) {
            odd_cycle++;
            if ( dfs(neibour, i, odd_cycle) ) { return true; }
        } 
        else if ( neibour != parent && odd_cycle % 2 != 0 ) {
            return true;
        }
    }

    return false;
}

int main() {
    static int odd_cycle = 0;

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        odd_cycle = 1;
        if ( !vis[i] )
            if ( dfs(i, -1, odd_cycle) ) 
                bench++;
    }
    
    if ( (n-bench)%2 != 0 ) bench++;

    cout << bench << endl;
        
    return 0;
}
