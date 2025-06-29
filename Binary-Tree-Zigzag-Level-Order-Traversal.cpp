#include <bits/stdc++.h>
using namespace std;

/*

    1. Controlling the Nodes per level Using BFS() :
    u cant inserting new nodes into queue until the old ones comes out

    for(i = 1 to levelSize) 
        q.pop();

    even the new Ones wont process until the old Ones Got REMOVED. <giving the real level size>

    2. Deque to Vector : 
    only the Deque can be used to inserting in front/back
    and 
    [ ans.pushBack(vector<int>(Deque.begin(), Deque.end()). ] --> convert it into normal array,vector.

*/

vector<vector<int>> zigzagLevelOrder(treeNode* root) {
    vector<vector<int>> ans;
    queue<treeNode*> q;
    int levelSize = 0, direction = 0;

    q.push(root);
    while( !q.empty() ) {
        levelSize = q.size();
        deque<int> level;

        for(int i = 1; i <= levelSize; i++) {
            treeNode* node = q.front(); q.pop();

            if (direction) 
                level.push_back(node->val);
            else
                level.push_front(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        ans.push_back(vector<int>(level.begin(), level.end()));
        direction = !direction;
    }

    return ans;
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

        void bfs() {
            queue<treeNode*> q;
            q.push(root);

            while (!q.empty()) {
                treeNode* node = q.front();
                q.pop();

                cout << node->val << " ";

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            cout << endl;
        }
        
        vector<int> BFS() {
            vector<int> result;
            queue<treeNode*> q;
            q.push(root);

            while (!q.empty()) {
                treeNode* node = q.front();
                q.pop();

                result.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            return result;
        }

        vector<vector<int>> zigzagLevelOrder(treeNode* root) {
            vector<vector<int>> ans;
            queue<treeNode*> q;
            int levelSize = 0, direction = 0;

            q.push(root);
            while( !q.empty() ) {
                levelSize = q.size();
                deque<int> level;

                for(int i = 1; i <= levelSize; i++) {
                    treeNode* node = q.front(); q.pop();

                    if (direction) 
                        level.push_back(node->val);
                    else
                        level.push_front(node->val);

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                
                ans.push_back(vector<int>(level.begin(), level.end()));
                direction = !direction;
            }

            return ans;
        }
};




int main() {
    BST p;

    p.insert(8);
    p.insert(3);
    p.insert(10);
    p.insert(1);
    p.insert(6);
    p.insert(14);
    p.insert(4);
    p.insert(7);
    p.insert(13);

    vector<vector<int>> res = p.zigzagLevelOrder(p.root);

    for(auto& x : res) {
        for(auto& xx : x) {
            cout << xx << " ";
        }
        cout << endl;
    }

    return 0;
}
