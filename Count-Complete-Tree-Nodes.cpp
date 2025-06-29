#include <bits/stdc++.h>
using namespace std;


// lazy way.



int BFS(treeNode* root) {
    int nodeCount = 1;

    queue<treeNode*> q;
    q.push(root);

    while (!q.empty()) {
        treeNode* cur = q.front(); q.pop();

        if (cur->left) q.push(cur->left), ++nodeCount;
        if (cur->right) q.push(cur->right), ++nodeCount;
    }

    return nodeCount;
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
   
    cout << BFS(b.root) << endl;

    return 0;
}
