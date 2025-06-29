#include <bits/stdc++.h>
using namespace std;

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

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<TreeNode*> q;
    double sum;

    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        sum = 0.00;

        for(int i = 1; i <= levelSize; i++) {
            TreeNode* cur = q.front(); q.pop();

            sum += (double)cur->val;
            
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        ans.push_back((double)sum/(double)levelSize);
    }

    return ans;
}

int main() {
    BST b;

    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(0);
    b.insert(4);
   
    vector<double> res = averageOfLevels(b.root);
    for(double& x : res) cout << x << " "; 
    cout << endl;

    return 0;
}
