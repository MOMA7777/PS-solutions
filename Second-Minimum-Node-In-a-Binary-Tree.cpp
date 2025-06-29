#include <bits/stdc++.h>
using namespace std;


// exploiting the fact that is The Root of the tree is the samllest value 
// in it
//
// then do early exit once u encounter value != root.
// in [left, right] sub-trees.
//
// because of the tree unique property we dont have to 
// traverse too much
//
// left and right integer get the nearest values 
// dont equal the root from both left, right sub-trees.
//
// but there is 3 cases:
//
// 1 - left and right = -1, no unique numbers in l,r subs
// 2 - there's unique numbers in one of the two subs.
// 3 - there's unique numbers in both subs
//
//
// To handle case 1,2 ==> just return max(l,r).
// if two is -1, return the max will return the -1.
// if one of them is -1 and the other is not returing the max will get u the value != -1.
//
// but for the third one we want the second smallest so 
// we want the minimum of the left and the right.






int helper(TreeNode* root, int& mn) {
    if (root == nullptr) return -1;
    if (root->val != mn) return root->val;

    int left = helper(root->left, mn);
    int right = helper(root->right, mn);

    if (left != -1 and right != -1) 
        return min(left, right);
    else 
        return max(left, right);
}

int findSecondMinimumValue(TreeNode* root) {
    if (root == nullptr) return -1;
    
    int mn = root->val;
    
    return helper(root, mn);
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

            if (v <= node->val) 
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

















int helper(TreeNode* root, int& mn) {
    if (root == nullptr) return -1;
    if (root->val != mn) return root->val;

    int left = helper(root->left, mn);
    int right = helper(root->right, mn);

    // one of them is -1 --> return the other.
    // both are -1 --> doesn't matter.
    // both not -1 --> we want the smallest.
    //

    if (left != -1 and right != -1) 
        return min(left, right);
    else 
        return max(left, right);
}

int findSecondMinimumValue(TreeNode* root) {
    if (root == nullptr) return -1;
    
    int mn = root->val;
    
    return helper(root, mn);
}


int main() {
    
    return 0;
}
