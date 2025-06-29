#include<bits/stdc++.h>
using namespace std;

/*

    Constructing BST without REALLY constructing
    --------------------------------------------

    if we have 3 nodes {1,2,3}

    and the root is {2} 

    then what ever the combination of [1,3] it will always be:

                                2
                               / \
                              1   3
    
    u cant say :
                                2           or          2
                                 \                     /
                                  3                   1
                                 /                     \
                                 1                      3


    By Simple method called dp and catalan's number
    we can count for any BST for any number number of nodes.


    first lets agree that if u have empty tree aka node = 0, it will be one
    dp[0] = 1;
    and if u have one node, it will also count one unique BST
    dp[1] = 1;

    For every node after 0, 1 WE COUNT:
    - number of node in [left].
    - number of node in [right].

    and get them like recursion-way "Bottom-UP", we have 1 - {number of nodes totally}, 2 - {current ROOT}
    
    - n = 4, rt = 1
    l = 0, r = 3 ==> 1 * 5 = 5.

    - n = 3, rt = 2
    rt = 2
    l = 1, r = 1 ==> 1 * 1 = 1. 


    but this assume we have already calculated the number of unique_BST for every number of nodes.
    but if we as we say calculate them "Bottom-UP", for every new nodes we can use the old ones,

    for Example
    -----------
    n = 4, root = 4
    we have calculated that for root = 3 ==> { dp[3] = 10 }

    no we can get use of that for root = 4
    left = 3, right = 0 
    dp[left] = 10, dp[right] = 1.

    so for n = 4, root = 4
    dp[4] = 10 * 1 = 10



*/

int numTrees(int n) {
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int node = 2; node <= n; ++node) {
        for(int root = 1; root <= node; ++root) {
            int left = root - 1;
            int right = node - root;

            dp[node] += dp[left] * dp[right];
        }
    }

    return dp[n];
}


int main() {



    return 0;
}
