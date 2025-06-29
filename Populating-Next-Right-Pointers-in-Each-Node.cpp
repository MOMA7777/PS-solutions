#include <bits/stdc++.h>
using namespace std;

/*

    start node : take the leftMost node at every level.

    cur node : traverse left to right assigning

    1 - cur->left->next to cur->right.
    2 - cur->right->next to cur->next->left.

*/

// O(n) time, O(1) space.
Node* connect(Node* root) {
    if (!root) return nullptr;

    Node* start = root; //start of each level.

    while (start->left) {    
        Node* cur = start;

        while (cur) {
    
            cur->left->next = cur->right;
    
            if (cur->next) 
                cur->right->next = cur->next->left;
    
            cur = cur->next;
        }
        
        start = start->left;
    }
    
    return root;
}



// BST approach.
Node* connect(Node* root) {
    if (root == nullptr) return nullptr;

    queue<Node*> q;
    q.push(root);
    Node* perv = nullptr;

    while (!q.empty()) {
        int levelSize = q.size();

        for(int i = 1; i <= levelSize; i++) {
            Node* cur = q.front(); q.pop();
            
            if (!prev) { perv = cur; }
            else {
                perv->next = cur;
                perv = cur;
            }

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        perv = nullptr;
    }

    return root;
}
















class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



























int main() {



    return 0;
}
