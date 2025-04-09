#include <bits/stdc++.h>
using namespace std;


/* 

   Not very simple but iam lazy to simplify it :( 

*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> stck;
        string token;
        int balance = 0;
        
        for (int i = 0; i < s.size(); i++) {
            token += s[i];

            if (s[i] == '(') ++balance;
            else             --balance;
            
            
            if (balance == 0 && i != 0) stck.push_back(token), token.clear();
        }
        
        string result;
        for (auto & str : stck) {
            str.erase(str.begin());
            str.pop_back();

            result += str;
        }

        return result;

    }
};
























typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} node ;


void insert(node *& head, int value) {
    node* newNode = new node;
    newNode->val  = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode; // First node
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void show(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    
    printf("\n");
}








void push(node *& top, int x) {
    node *newNode = new node;
    
    newNode->val  = x;
    newNode->next = NULL;
    
    newNode->next = top;
    top = newNode;
}

node *peek(node *& top) {
    if (top == NULL) { 
        cout << "Stack Underflow\n";
        return NULL;
    }
        
    return top;
}

int peek_element(node *& top) {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }
    
    return top->val;
}

void pop(node *& top) {
    node *old = top;
    top = top->next;

    delete old;
} 









int main() {

    return 0;
}

