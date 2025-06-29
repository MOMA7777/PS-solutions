#include <bits/stdc++.h>
using namespace std;

/* 
    Symmetrism with Recursion : 
    ---------------------------

    normal case
    P.L and Q.L , P.R and Q.R [LL and RR].

    symmetrism
    P.L and Q.R , P.R and Q.L [LR and RL].


 * */




bool mirror(treeNode* p, treeNode* q) {
    if (!p and !q) return true;
    if (!p or !q) return false;

    if (p->val != q->val) return false;

    return mirror(p->left, q->right) && mirror(p->right, q->left);
}

bool isSymmetric(treeNode* root) {
    treeNode* p = root->left;
    treeNode* q = root->right;

    return mirror(p, q);
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


bool mirror(treeNode* p, treeNode* q) {
    if (!p and !q) return true;
    if (!p or !q) return false;

    if (p->val != q->val) return false;

    return mirror(p->left, q->right) && mirror(p->right, q->left);
}

bool isSymmetric(treeNode* root) {
    treeNode* p = root->left;
    treeNode* q = root->right;

    return mirror(p, q);
}



int main() {

    return 0;
}
