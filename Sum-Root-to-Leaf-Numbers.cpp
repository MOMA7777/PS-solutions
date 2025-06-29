#include <bits/stdc++.h>
using namespace std;










void helper(TreeNode* root, int& totalSum, string path) {
    if (!root) return;

    path.push_back(root->val + '0');

    if (!root->right and !root->left) {
        totalSum += stoi(path);
        return;
    }

    helper(root->left,  totalSum, path);
    helper(root->right, totalSum, path);
}

int sumNumbers(TreeNode* root) {
    int totalSum = 0;
    string path;

    helper(root, totalSum, path);

    return totalSum;
}
















struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

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
    BST p;

    p.insert(2);
    p.insert(1);
    p.insert(3);

    cout << sumNumbers(p.root) << endl;

    return 0;
}
