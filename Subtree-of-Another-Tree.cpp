#include <bits/stdc++.h>
using namespace std;

// one for traversing and searching.
// two for checking.

bool isSameTree(TreeNode* root, TreeNode* subRoot) {
    if (!root and !subRoot) return true;

    if (!root or !subRoot) return false;
    if (root->val != subRoot->val) return false;

    return isSameTree(root->left, subRoot->left) and isSameTree(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;
    if (!root) return false;

    if ( isSameTree(root, subRoot) ) return true; //matching checking.

    return isSameTree(root->left, subRoot) or isSameTree(root->right, subRoot);
}




















/* array version */

bool isSame(vector<int>& s, int st, vector<int>& t) {
    for(int i = st, j = 0; i < t.size(), j < t.size(); i++, j++) {
        if (s[i] != t[j]) return false;
    }

    return true;
}

bool isSubarray(vector<int>& a, vector<int>& b) {
    int sa = a.size();
    int sb = b.size();

    for(int i = 0; i < sa; i += sb) {
        if ( isSame(a, i, b) ) return true;
    }

    return false;
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
    vector<int> a = {3,7,4,3,5,6,7,3,1,3,3,6,8,3,5};
    vector<int> b = {1,2,3};

    cout << isSubarray(a, b) << endl;

    return 0;
}
