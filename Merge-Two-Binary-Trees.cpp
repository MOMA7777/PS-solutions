#include <bits/stdc++.h>
using namespace std;

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

/*

    why keep traversing for the existing node, 
    while the existing node will gives u all the descendants ?


tree1 :                                 tree2 :
             3
            /                                       null
           5   
            \
             4

           keep traversing with 
           (3, null) 
           (5, null)
           (4, null)

           if u took 3 will give u 5 and 4 and null of 4 by gurantee.

           thats why base cases:
            if (ONE_OF_THE_ROOTS == NULL) return THE_OTHER.

*/

TreeNode* mergeTrees(TreeNode* s, TreeNode* t) {
    if (s == nullptr) return t;
    if (t == nullptr) return s;

    TreeNode* m = new TreeNode(s->val + t->val);

    m->left  = mergeTrees(s->left, t->left);
    m->right = mergeTrees(s->right, t->right);

    return m;
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
