#include <bits/stdc++.h>
using namespace std;


// in Recursion try to make every thing local.


class Solution {
public:
TreeNode* build(unordered_map<int,int>& mp, vector<int>& postorder, int& postIdx, int left, int right) {
    if (left > right) return nullptr;

    int value = postorder[postIdx--];
    TreeNode* cur = new TreeNode(value);
    int idx = mp[value];

    cur->right = build(mp, postorder, postIdx, idx+1, right);
    cur->left  = build(mp, postorder, postIdx, left, idx-1);

    return cur;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mp;

    for(int i = 0; i < inorder.size(); i++)  
        mp[inorder[i]] = i;

    int postIdx = postorder.size()-1;

    return build(mp, postorder, postIdx, 0, inorder.size()-1);
}

};


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

int postIdx = 0;
int idx = 0;

TreeNode* build(unordered_map<int,int>& mp, vector<int>& postorder, int left, int right) {
    if (left > right) return nullptr;

    TreeNode* cur = new TreeNode( postorder[postIdx] );
    idx = mp[postorder[postIdx]];
    --postIdx;

    cur->right = build(mp, postorder, left, idx-1);
    cur->left  = build(mp, postorder, idx+1, right);

    return cur;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mp;

    for(int i = 0; i < inorder.size(); i++)  
        mp[inorder[i]] = i;

    postIdx = postorder.size()-1;

    return build(mp, postorder, 0, 4);
}


int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    BST p;
    p.root = buildTree(inorder, postorder);



    return 0;
}
