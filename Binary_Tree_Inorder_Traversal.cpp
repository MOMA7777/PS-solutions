#include <bits/stdc++.h>
using namespace std;

/*
 *
 *  ISOLATION of functions in Recursion.
 *
 * */

class Solution {
public:
    void inOrder(TreeNode * node, vector<int> & ans) {
        if (node == nullptr) return;

        if (node->left) inOrder(node->left, ans);
        ans.push_back(node->val);
        if (node->right) inOrder(node->right, ans);
    }

    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }

};



int main() {
    


    return 0;
}
