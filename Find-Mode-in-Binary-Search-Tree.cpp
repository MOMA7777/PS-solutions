#include <bits/stdc++.h>
using namespace std;

/*

   just normal array-like problem

   new trick:
   when counting maximum frequancy element in array 'sorted' and 
   every time u have to update the maximum and hence 
   add the new element and remove all the ones u added.

    u can just type
    freq = { newElement };

    aka 

    1 clear the vector.
    2 push the new one.


    In General : 
    -------------
    1 init current-count, max-count, current-element.
    2 traverse the array 
        if current-element = pervious-element 
            increase current-count + 1.
            update   maximum-count.
        else
            current-count = 1.
    
    3 
        if [ current-count > maximum-count ]
            remove all elements u pushed to most_freq_elements_array.
            add current-element to most_freq_elements_array.
        but if [ current-count = maximum-count ] " more than one element share max occurance.
            add current-element to most_freq_elements_array.
*/

TreeNode* cur = nullptr;
int cnt = 0, mxCnt = 0;
void helper(TreeNode* root, vector<int>& mode) {
    if (root == nullptr) return;

    helper(root->left, mode);

    if (cur and cur->val == root->val) ++cnt;
    else cnt = 1;

    if (cnt == mxCnt) {
        mode.push_back(root->val);
    }
    else if (cnt > mxCnt) {
        mxCnt = cnt;
        mode = { root->val };
    }
    
    cur = root;

    helper(root->right, mode);
}

vector<int> findMode(TreeNode* root) {
    vector<int> mode;
    
    helper(root, mode);

    return mode;
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

            if (v <= node->val) 
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
    b.insert(2);
    b.insert(3);
    b.insert(3);
    b.insert(3);
   
    vector<int> ans = findMode(b.root);

    for(auto& x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
