#include <bits/stdc++.h>
using namespace std;





void inorder__(TreeNode* root, vector<int>& res) {
    if (!root) return;

    if (root->left)  inorder__(root->left, res);
    res.push_back(root->val);
    if (root->right) inorder__(root->right, res);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> res;

    inorder__(root, res);

    return res[k-1];
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

    // 0 1 2 3 4 
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(0);
    b.insert(4);
   
    cout << kthSmallest(b.root, 2) << endl; // 1

    return 0;
}
