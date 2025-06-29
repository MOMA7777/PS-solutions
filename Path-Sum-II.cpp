#include <bits/stdc++.h>
using namespace std;


/*

    Path Optimizations in BST traversing
    ------------------------------------

    1 
        void helper(vector<>& path, ....
            if (leaf-encounter)
                do-Logic and dont return now.

            goLeft  (root.Left);
            goRight (root.Right);
            path.pop();

    2
        void helper(vector<> path, ....
            if (leaf-encounter)
                do-Logic and return now.

            goLeft  (root.Left);
            goRight (root.Right);


    (1) is doing manual backtracking using pop()
    which is works when reaching leaf node where L = null, R = null,
    it popes the last node which remains the current path correctly.


*/


void helper(TreeNode* root, vector<int>& path, int t, vector<vector<int>>& ans) {
    if (root == nullptr) return;

    path.push_back(root->val);
    t -= root->val;

    if (!root->left and !root->right and t == 0) 
        ans.push_back(path);

    helper(root->left,  path, t, ans);
    helper(root->right, path, t, ans);

    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;

    helper(root, path, targetSum, ans);

    return ans;
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

    p.insert(5);
    p.insert(4);
    p.insert(8);

    p.insert(11);
    p.insert(13);
    p.insert(4);
    
    p.insert(7);
    p.insert(2);
    p.insert(5);
    p.insert(1);
   

    vector<vector<int>> res = pathSum(p.root, 22);

    for(auto& x : res) {
        for(auto& xx : x) { 
            cout << xx << " ";
        }
        cout << endl;
    }

    return 0;
}
