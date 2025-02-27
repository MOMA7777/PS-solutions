#include <bits/stdc++.h>
using namespace std;


/* 
   s[top++] ==> assing first, then update.
   s[--top] ==> update first, then assing.

   it dont require any extra memory it depend on just 0,1 indexes for comparisons only 
   since there's no poping and pushing this solution only depend on 0,1 index for comparison.

   increasment vs decreasment !
   s[t++] ==> s[0], t = 1; acsses zero.
   s[--t] ==> s[0], t = 0; acsses zero.

   looks like palindrome pattern

   (()):
   first top will increase for ( and ( 
   then will decrease for ) and ).

   increase for left par and decrease for right par.

*/

// O(1) space, O(n) time.
class Solution {
public:
    bool isValid(string s) {
        int top = 0;
        for (auto &&c: s) {
            char need;
            switch (c) {
                case '[': case '(': case '{': s[top++] = c; continue;
                case ']': need = '['; break; 
                case ')': need = '('; break;
                case '}': need = '{'; break;
            }

            if (top == 0 || s[--top] != need) return false;
        }

        return top == 0;
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

