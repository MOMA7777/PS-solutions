#include <bits/stdc++.h>
using namespace std;

// Avoid traversing left when its not nessacry usign if conditions.

bool check(TreeNode* node) {
        return node != nullptr and !node->left and !node->right;
    }

void dfs(TreeNode* root, int& sum) {
    if (root == nullptr) return;

    if (check(root->left)) {
        sum += root->left->val;
    }
    else {
        dfs(root->left, sum);    
    }

    dfs(root->right, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr) return 0;

    int sum = 0;
    dfs(root, sum);

    return sum;
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
    b.insert(-2);
    b.insert(4);
   
    cout << sumOfLeftLeaves(b.root) << endl;

    return 0;
}
