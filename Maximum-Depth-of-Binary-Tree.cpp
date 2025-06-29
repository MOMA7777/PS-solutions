#include <bits/stdc++.h>
using namespace std;


/*
    Recursion Variables must sent as Parameters
    Otherwise will be forgetten


    Rec() {
        mx = max(new, old);         WRONG.
    }

    Rec(old, new) {
        mx = max(new, old);         CORRECT.
    }

 * */


class Solution {
public:
    int depth = 0, mx = 0;

    void currentDepth(TreeNode* root, int depth) {
        if (root == nullptr) return;

        mx = max(mx, depth);

        if (root->left) currentDepth(root->left, depth+1);
        if (root->right) currentDepth(root->right, depth+1);
    }

    int maxDepth(TreeNode* root) {
        currentDepth(root, 1);

        return mx == 0 ? 0 : mx+1;
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
        int mx, depth;
        treeNode * root;

        BST() : root(nullptr), mx(1), depth(1) {}

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

        void inOrder(treeNode* node) {
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
    Solution sol;

    p.insert(7);
    p.insert(2);
    p.insert(9);
    p.insert(10);
    p.insert(8);

    cout << sol.maxDepth(p.root) << endl;

    return 0;
}
