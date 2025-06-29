#include <bits/stdc++.h>
using namespace std;

/*

    How to Detect Two Elements that violates a Sequence's Order ?

    assume we have

    [1 2 4 3 5] ==> 3,4 violates the order ADJACENT.
    [5 2 3 4 1] ==> 1,5 violates the order NON-ADJACENT.


    so we want to handle the both cases where the exact two elements can be ADJACENT, NON-ADJACENT.

    we will have 3 pointers : perv, first, second

    first for saving the first violation element.
    second for saving the second violation element.

    perv for tracking current, perv and compare them


    [1 2 4 3 5]
    perv = 4, cur = 3

    now first didnt assigned before so { first = perv = 4 } and { second = cur = 3 }

    by Continuing we wont find any other violations so just swap them ==> [1 2 3 4 5] fixed.


    [5 2 3 4 1]
    
    perv = 5, cur = 2
    { first = perv = 5 } and { second = cur = 2 }

    lets Continue

    perv = 4, cur = 1
    { first is Assigned so we wont update it } and { second = cur = 1 }

    SO after all :
    { first = 5, second = 1 } swap them will get the sequence updated ==> [1 2 3 4 5].





    THE ONLY DIFFERENCE WE DO RECURSION WITH GLOBAL VARIBALES.
*/

treeNode* first = nullptr;
treeNode* second = nullptr;
treeNode* perv = new treeNode(LONG_MIN);

void check(treeNode* cur) {
    if (!cur) return;

    if (node->left) check(cur->left);

    if (perv && perv->val > cur->val) {
        if (!first) first = perv;
        second = root;
    }

    perv = root;

    check(cur->right);
}

void recoverTree(treeNode* root) {
    check(root);

    if (first and second) 
        swap(first->val, second->val);

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
