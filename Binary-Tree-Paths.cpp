#include <bits/stdc++.h>
using namespace std;



// not the solution of the problem, but just the main trick [sorry iam lazy dont judge me].

/*

    recursion(type& obj) vs recursion(type obj) :
    ---------------------------------------------

    The call by reference is the main reason why the object dont backtrack
    
    recursion(type & obj) --> wont backTrack/back to its pervious state when 
    leaving the StackFrame.

    recursion(type obj) --> will backtrack to its pervious states.
*/

void t(TreeNode* root, vector<int> path) {
    if (root == nullptr) return;

    path.push_back(root->val);

    if (!root->left and !root->right) {
        for(int i = 0; i < path.size(); i++) 
            cout << path[i] << " ";
        cout << endl;

        return;
    }

    t(root->left, path);
    t(root->right, path);
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

    vector<int> path;
    t(b.root, path);

    return 0;
}
