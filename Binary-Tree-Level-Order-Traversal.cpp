#include <bits/stdc++.h>
using namespace std;


// a little brute force.



class Solution {
public:
    void addDepthIdx(TreeNode* node, int depth, vector<vector<int>>& v) { // push values by level.
        if (node == nullptr) return;

        v[depth].push_back(node->val);
    
        if (node->left) addDepthIdx(node->left, depth+1, v);
        if (node->right) addDepthIdx(node->right, depth+1, v);
    }

    int maxDepth(TreeNode* root, int depth) { // count maximum depth in DFS.
        if (root == nullptr) return 0;

        int l = maxDepth(root->left, depth+1);
        int r = maxDepth(root->right, depth+1);

        return 1 + max(l, r);
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int depth = 0;

        int maxiumumDepth = maxDepth(root, depth);
        ans.resize(maxiumumDepth);

        addDepthIdx(root, depth, ans);

        return ans;
    }

};






struct treeNode {
    int val;
    treeNode * left;
    treeNode * right;

    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    treeNode(int v, treeNode *l, treeNode *r) : val(v), left(l), right(r) {}
};

class BST {
    public:
        treeNode * root;

        BST() : root(nullptr) {}

        treeNode * insert(treeNode *node, int v) {
            if (node == nullptr) 
                return new treeNode(v); 

            if (v < node->val) 
                node->left = insert(node->left, v);
            else if (v > node->val) 
                node->right = insert(node->right, v);

            return node;
        }

        void insert(int v) {
            root = insert(root, v);
        }

        void inOrder(treeNode * node) {
            if (node == nullptr) return;

            if (node->left) inOrder(node->left);
            cout << node->val << " ";
            if (node->right) inOrder(node->right);
        }

        void inOrder() {
            inOrder(root);
            cout << endl;
        }
};





int main() {
    BST p;

    p.insert(10);
    p.insert(5);
    p.insert(2);
    p.insert(12);
    p.insert(11);
    p.insert(15);

    Solution sol;
    vector<vector<int>> res = sol.levelOrder(p.root);
    

    return 0;
}
