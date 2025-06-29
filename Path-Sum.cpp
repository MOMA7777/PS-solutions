#include <bits/stdc++.h>
using namespace std;

/* 
    Functional-Sytle Recursion :
    ----------------------------

    return hasPath(left, sum) || hasPath(right, sum) 

    it works like dfs but if -> hasPath(left, sum) ==> true,
    the other expression -> hasPath(right, sum) WONT EVEN EVALUATED.

    and It Divide the subTree into 2 parts 
    withOut encounter the Other for any Operation.... [And they can be passed the same Parameter].
*/

bool hasPathSum(treeNode* root, int target) {
    if (!root) return false;

    if (!root->left and !root->right) return root->val == target;

    int remainSum = target - root->val;
    return hasPathSum(root->left, remainSum) || hasPathSum(root->right, remainSum);
}







struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;

    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    treeNode(int v, treeNode *l, treeNode *r) : val(v), left(l), right(r) {}
};

class BST {
    public:
        treeNode* root;

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










bool hasPathSum(treeNode* root, int targetSum) {
        
}








int main() {
    BST b;

    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(0);
    b.insert(4);

    cout << minDepth(b.root) << endl;

    return 0;
}
