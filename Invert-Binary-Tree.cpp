#include <bits/stdc++.h>
using namespace std;


// Bottom-Top invertion
//
//  1 Save the current left.
//  2 Assign current left to current right (DFS-recursive).
//  3 Assign current right to saved left (DFS-recursive).
//



TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode* tmp = root->left;

    root->left  = invertTree(root->right);
    root->right = invertTree(tmp);

    return root;
}








struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

class BST {
    public:
        TreeNode * root;

        BST() : root(nullptr) {}

        TreeNode * insert(TreeNode *node, int v) {
            if (node == nullptr) 
                return new TreeNode(v); 

            if (v < node->val) 
                node->left = insert(node->left, v);
            else if (v > node->val) 
                node->right = insert(node->right, v);

            return node;
        }

        void insert(int v) {
            root = insert(root, v);
        }

        void inOrder(TreeNode * node) {
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


void bfs(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        cout << current->val << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }
}




int main() {
    BST b;

    b.insert(4);
    b.insert(2);
    b.insert(7);
    b.insert(1);
    b.insert(3);
    b.insert(6);
    b.insert(9);

    TreeNode* tmp = invertTree(b.root);

    bfs(tmp);   
    cout << endl;

    return 0;
}
