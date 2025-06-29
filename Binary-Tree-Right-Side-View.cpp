#include <bits/stdc++.h>
using namespace std;



// Surface traversing using expandable vector 'genius technique 'not mine' i dont know what to call it'.

void preorder(TreeNode* root, vector<int>& ans, int i) {
    if (!root) return;

    if (ans.size() == i) ans.push_back(root->val);

    preorder(root->right, ans, i+1);
    preorder(root->left,  ans, i+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    
    preorder(root, ans, 0);

    return ans;
}


vector<int> rightSideView_2(TreeNode* root){
    vector<int> ans;
    queue<TreeNode*> q;

    TreeNode* cur = nullptr;

    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();

        for(int i = 0; i < levelSize; i++) { 
            cur = q.front(); q.pop();

            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        ans.push_back(cur->val);
        cur = nullptr;
    }
   
    return ans;
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

    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(0);
    b.insert(4);

    vector<int> res = rightSideView(b.root);

    for(auto& x : res) cout << x << " ";
    cout << endl;

    return 0;
}
