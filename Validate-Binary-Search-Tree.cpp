#include <bits/stdc++.h>
using namespace std;

/*
    the BST fails if 

    node->left > current.
    node->right < current.
    
    How we Send [node->left, node->right, current] in Recursion parameter ? 

    we can for every left dfs travese --> send the current and compare it with node->left.
    we can for every right dfs traverse --> send the current and compare with node->right.

    USING "RANGE UPDATING"

     10
    /  \
   5    15
       /  \
      6   20



    node = 10.

    left --> send current to max, right --> send current to min.

    1. left = (5, MN, 10) allowed.
    2. left = (null, MN, 5) allowed.
    
    back to 5

    3. right = (null, 5, 10) allowed.

    back to 10

    4. right = (15, 10, MX) allowed.
    5. left = (6, 10, 15) VIOLATION.

    So it about HOW TO SEND [LEFT, RIGHT, CURRENT] IN RIGHT WAY.

*/

bool validate(treeNode* node, ll mn, ll mx) {
    if (node == nullptr) return true;

    if (node->val < mn || node->val > mx) return false;

    return validate(node->left, mn, node->val) and validate(node->right, node->val, mx);
}

bool isValid(treeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
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
