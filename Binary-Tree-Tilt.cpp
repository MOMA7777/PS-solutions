#include <bits/stdc++.h>
using namespace std;

/*

    handling two opposite operations one by recursion and the other by global varibles.

    sum --> handled by recursion cause it dont effect the internal structure [left - right].
    abs --> handled by global variable.

    tilt is just the total sum of individual sum of each node.
    but title isn't inherited by the hole tree.

    means we need to save the internal tree property.

    tilt(node) = node_tilt;
    totalTilt = tilt(every node in the tree).

    tilt(node) = abs[ sum(left) - sum(right) ]; can't effect the internal structure.

    but we need the sum(left), sum(right) to get every tilt(node) correctly.

    this done by:
        1 init left, right integers.
        2 do PostOrder traversing to process children first.
        3 return current-node-value + left integer + right integer.             'this can be done in many ways'


*/

int totalTilt = 0;
int helper(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = helper(root->left);
    int right = helper(root->right);
    
    totalTilt += abs(left - right);

    return root->val + left + right;
}

int findTilt(TreeNode* root) {
    helper(root);

    return totalTilt;
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
