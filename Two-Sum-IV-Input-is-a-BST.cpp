#include <bits/stdc++.h>
using namespace std;



// two pointers approach is faster, but longer [iam lazy].


bool helper(TreeNode* root, int k, unordered_set<int>& st) {
    if (root == nullptr) return false;

    if (st.count(k - root->val)) return true;
    else st.insert(root->val);

    bool f1 = helper(root->left, k, st);
    bool f2 = helper(root->right, k, st);

    return f1 or f2;
}

bool findTarget(TreeNode* root, int k) {
    unordered_set<int> st;

    return helper(root, k, st);
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
    b.insert(67);
    b.insert(23);
    b.insert(61);
   
    cout << findTarget(b.root, 9) << endl;

    return 0;
}
