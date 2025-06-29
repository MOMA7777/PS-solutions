#include <bits/stdc++.h>
using namespace std;

// InOrder Give the right sort of sequence of numbers if BST HOLD ITS CONDITIONS.
// + InOrder : left - root - right.

// if no left it will print/whatever the node.

/*
        10
       /
      5
       \
        9


InOrder : 5 - 9 - 10.

*/

TreeNode* cur = nullptr;

void inOrder(TreeNode* node, long long& mn) {
    if (node == nullptr) return;

    if (node->left) 
        inOrder(node->left, mn);

    if (cur and abs(cur->val - node->val) < mn) 
        mn = abs(cur->val - node->val);
    cur = node;

    if (node->right) 
        inOrder(node->right, mn);
}

int getMinimumDifference(TreeNode* root) {
    long long mn = LONG_MAX;
        
    inOrder(root, mn);

    return mn;
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
    BST b;

    b.insert(10);
    b.insert(155);
    b.insert(356);
    b.insert(-23);
    b.insert(56);
   
    cout << getMinimumDifference(b.root) << endl;

    return 0;
}
