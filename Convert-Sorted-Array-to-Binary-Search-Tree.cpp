#include <bits/stdc++.h>
using namespace std;

/*

    1. Building BST itself doesnt gurantee linking between nodes.
    [-10,-3,0,5,9]

    current = new TreeNode(-3), but how to say 

    the node (-3) is LEFT to the node (0) ? 

    the Recursion solve this by 

    node->left  = buildBST(.....
    node->right = buildBST(.....



    2. Constructing Base Case
    what breaks the whole recursion is [l > r] , left bigger than right
    or right smaller than left which not make any sense.


 * */



class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if (left > right) return nullptr;

        int m = l + (r - l) / 2;

        TreeNode* root = new TreeNode(nums[m]);

        root->left = buildBST(nums, l, m-1);
        root->right = buildBST(nums, m+1, r);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return buildBST(nums, 0, nums.size()-1); 
    }
};










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
        int mx, depth;
        treeNode * root;

        BST() : root(nullptr), mx(1), depth(1) {}

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

        void inOrder(treeNode* node) {
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

    return 0;
}
