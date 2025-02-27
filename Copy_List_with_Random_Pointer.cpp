#include <bits/stdc++.h>
using namespace std;



/*
 *  Copy without Copy.
 *  -----------------
 *  mapping Original ==> Copy.
 *  will make u acsses original list element but their copies.
 *
 *  next:
 *  A --> A`
 *  B --> B`
 *  C --> C`
 *
 *  random:
 *  A`.random = mp[A.random] = mp[C] = C`.
 *  B`.random = mp[B.random] = mp[A] = A`.
 *  ...
 *
 *  original list will acsses random pointers automatically so u dont have to copy them.
 *
 * */





class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL; 

        map<Node*, Node*> mp; 

        Node* org = head;
        Node* newHead = new Node(org->val);
        mp[org] = newHead;
        Node* cpy = newHead;

        while (org->next) {
            cpy->next = new Node(org->next->val);
            org = org->next;
            cpy = cpy->next;
            mp[org] = cpy; 
        }

        org = head;
        cpy = newHead;
        while (org) {
            if (org->random) {
                cpy->random = mp[org->random]; 
            }
            org = org->next;
            cpy = cpy->next;
        }

        return newHead;
    }
};



















typedef struct node {
    int val;
    struct node *next;
    struct node *random;
} node ;

void insert(node** head, int value) {
    node* newNode = malloc(sizeof(node));
    newNode->val  = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // First node
        return;
    }

    node* temp = *head;
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

























































int main() {

     

    return 0;
}

