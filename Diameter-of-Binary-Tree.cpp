#include <bits/stdc++.h>
using namespace std;

/*
    PostOrder --> process left and right of the node first.
    Diameter --> the sum of left + right of the node.

    so if we found a way to calculate the depth of the children first
    the we assign the sum to current node
    and compare the sum of each node to get the maximum we will calculate the diameter.


    1 - calculate the depth of left + depth of right first USING PostOrder traversal.
    2 - calculate the sum of left & right.
    3 - update the sum of left & right until u get maximum.
    4 - return maximum.


    In our case the diameter might not pass through the root.
    so we dont want our depth-calculations to start from the root.

    that's why we pick up PostOrder-Traversing.






    Observations:
    --------------

    in PostOrder --> u calculate the depth "Bottom-Up".
    in PreOrder --> u calculate the depth "Up-Down".

    PostOrder
        8   ==> 4
       /  
     3      ==> 3
    / \                                             .
   1   6    ==> 2
      / \                                           .
     4   7  ==> 1 


    PreOrder
        8   ==> 1
       /  
     3      ==> 2
    / \                                             . 
   1   6    ==> 3
      / \                                           .
     4   7  ==> 4 

*/

int maxDiameter = 0;

int depth(TreeNode* root) {
    if (root == nullptr) return 0;

    int left  = depth(root->left);
    int right = depth(root->right);

    maxDiameter = max(maxDiameter, left+right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    depth(root);

    return maxDiameter;
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
