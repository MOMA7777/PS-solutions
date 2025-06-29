#include <bits/stdc++.h>
using namespace std;

// link : https://codeforces.com/contest/115/problem/A


/*

    1- Employees under the same Heirachy can be in the same Group

    employees with degree = 1 {same Group}
    employees with degree = 2 {same Group}
    employees with degree = 3 {same Group}
    ....

    its like a FOREST Graph : Normal graph but 
    1- acyclic
    2- disConnected.

    we can treat employees as nodes
    and the number of Edges connecting them with the root of their tree ==> Heirachy level.
    employees with the same Heirachy level will be under the same group...

    Heirachy -> how much they are far from the Manager aka : the root.

    [Employees Under the same Heirachy = Under the same Group].
    =
    [Nodes Under the same Depth = Under the same Group].

    its like finding the maximum depth problem...



To review FOREST : 
------------------
1:
https://www.google.com/imgres?q=forest%20graph&imgurl=https%3A%2F%2Fstatic.cambridge.org%2Fbinary%2Fversion%2Fid%2Furn%3Acambridge.org%3Aid%3Abinary%3A20171027092037172-0306%3A9781316105450%3A08931fig2_1.png%3Fpub-status%3Dlive&imgrefurl=https%3A%2F%2Fwww.cambridge.org%2Fcore%2Fbooks%2Fapplying-graph-theory-in-ecological-research%2Fshapes-of-graphs-trees-to-triangles%2F6F7A9487D10EF5ED28A83F7B035E7FDC&docid=PzwGlUuKpSbWBM&tbnid=vZT2DZ_T1woCQM&vet=12ahUKEwjOpsOkz82NAxUHRvEDHe0vII0QM3oECGQQAA..i&w=1048&h=801&hcb=2&ved=2ahUKEwjOpsOkz82NAxUHRvEDHe0vII0QM3oECGQQAA

2:
https://www.google.com/imgres?q=forest%20graph&imgurl=https%3A%2F%2Fwww.mathreference.org%2Fimages%2Fpages%2F393_en_4.svg&imgrefurl=https%3A%2F%2Fwww.mathreference.org%2Findex%2Fpage%2Fid%2F393%2Flg%2Fen&docid=ffZn_aCaNgmNmM&tbnid=HR1-Y3h9PIomiM&vet=12ahUKEwjOpsOkz82NAxUHRvEDHe0vII0QM3oECB4QAA..i&w=645&h=419&hcb=2&ved=2ahUKEwjOpsOkz82NAxUHRvEDHe0vII0QM3oECB4QAA

*/

const int N = 2003;
int maxDepth = 1;

vector<int> underHim[N];
bool vis[N];
int p[N];

void dfs(int i, int depth) {
    vis[i] = true;
    maxDepth = max(maxDepth, depth);

    for(auto& empl : underHim[i]) {
        if (!vis[empl]) 
            dfs(empl, depth+1);
    }
}

int main() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];

        if (p[i] != -1) 
            underHim[p[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        if (!vis[i] and p[i] == -1) 
            dfs(i, 1);
    }

    cout << maxDepth << endl;

    return 0;
}
