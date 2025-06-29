#include <bits/stdc++.h>
using namespace std;




// Global varibales slow the recursion.
// var = max(var, recursion(parameters)) --> good,effecient,fast way of recursion.

int helper(Node* p, int current_depth) {
    int mx = current_depth; 

    for(int i = 0; i < p->children.size(); i++) {
        mx = max(mx, helper(p->children[i], current_depth+1));
    }

    return mx;
}

int maxDepth(Node* root) {
    if (root == nullptr) return 0; 

    return helper(root, current_depth);
}









class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};




int main() {
    

    return 0;
}
