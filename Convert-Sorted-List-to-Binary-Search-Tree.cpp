#include <bits/stdc++.h>
using namespace std;



/* 
    InOrder Construction :
    ----------------------

    1- Go left.
    2- Construct the Node.
    3- Go right.

    inOrder --> save the Sorting property.

    while other traversal like : postOrder-preOrder, break and might not even 
    construct the BST.
*/






int countNodes(ListNode* head) {
    int count = 0;

    while (head) {
        ++count;
        head = head->next;
    }

    return count;
}

TreeNode* build(int n) {
    if (n <= 0) 
        return nullptr;

    TreeNode* left = build(n/2);

    TreeNode* root = new TreeNode(cur->val);
    root->left = left;

    cur = cur->next;

    root->right = build(n - n/2 - 1);

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int cnt = countNodes(head);
    if (cnt == 0) return nullptr;
    return build(cnt); 
}



















struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r) : val(v), left(l), right(r) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
