#include <bits/stdc++.h>
using namespace std;

// its valid also for counting height, aka the depth.



class Solution {
public:
    int checkHeight(treeNode* node) {
        if (!node) return 0; 

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; 

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; 

        if (abs(leftHeight - rightHeight) > 1) return -1; 

        return max(leftHeight, rightHeight) + 1; 
    }

    bool isBalanced(treeNode* root) {
        return checkHeight(root) != -1;
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
    



    return 0;
}
