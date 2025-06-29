#include <bits/stdc++.h>
using namespace std;

/*

    1 - get predecssor : {right-most node in the left sub-tree.}
    2 - make predecssor->right point to currentRoot->right to connect the tree leaves.
    3 - currentRoot->right = currentRoot->left, currentRoot->left = NULL.
    4 - move by currentRoot = currentRoot->right.

*/

void flatten(TreeNode* root) {
    if (root == nullptr) return;

    TreeNode* cur = root;

    while (cur) {
        if (cur->left) {
            TreeNode* pre = cur->left;
            
            while (pre->right) 
                pre = pre->right;
                
            pre->right = cur->right;
    
            cur->right = cur->left;
            cur->left = nullptr;
        }
    
        cur = cur->right;
    }
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

    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(0);
    b.insert(4);
   
    b.inOrder();

    return 0;
}
