#include <bits/stdc++.h>
using namespace std;


/*
    on of the hardest ever, 

    PreOrder = [root, left, right].
    InOrder  = [left, root, right].

    PreOrder priotize the root over left, right
    while InOrder give u for every root in PreOrder the exact real nodes on its right and on its left subtrees.

    for Example 
    pre = 3
    in  = [4, 3, 5]

    u exaclty know that 

    3'left  = 4.
    3'right = 5. 


    pre = 3
    in  = [4, 5, 6, 7, 8, 9, 3, 10, 11, 12, 13, 14].
                             *


    3's sub-left  [4  to  9]
    3's sub-right [10 to 14]

    So Recrusivly we can catch every node in `PreOrder` and locate it in `InOrder` to see its left, right USING DIVIDE AND CONQUER.
*/





int preOrderIndx = 0;        
unordered_map<int,int> inOrderIndx;

TreeNode* buildTree__(vector<int>& preorder, vector<int>& inorder, int left, int right) {
    if (left > right) return nullptr;

    int rootValue = preorder[preOrderIndx];
    TreeNode* root = new TreeNode(rootValue);

    ++preOrderIndx;
    
    int nextdirection = inOrderIndx[rootValue]; 

    root->left = buildTree__(preorder, inorder, left, nextdirection-1);
    root->right = buildTree__(preorder, inorder, nextdirection+1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    preOrderIndx = 0;

    for(int i = 0; i < inorder.size(); i++) 
        inOrderIndx[inorder[i]] = i;

    return buildTree__(preorder, inorder, 0, preorder.size()-1);
}
















struct treeNode {
    int val;
    treeNode * left;
    treeNode * right;

    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    treeNode(int v, treeNode *l, treeNode *r) : val(v), left(l), right(r) {}
};

class BST {
    public:
        treeNode * root;

        BST() : root(nullptr) {}

        treeNode * insert(treeNode *node, int v) {
            if (node == nullptr) 
                return new treeNode(v); 

            if (v < node->val) 
                node->left = insert(node->left, v);
            else if (v > node->val) 
                node->right = insert(node->right, v);

            return node;
        }

        void insert(int v) {
            root = insert(root, v);
        }

        void inOrder(treeNode * node) {
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
