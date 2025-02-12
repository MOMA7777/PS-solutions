//link : https://leetcode.com/problems/swap-nodes-in-pairs/description/

#include <stdio.h>
#include <stdlib.h>

node * swapPairs(node **head) {
    if (*head == NULL) return NULL;

    node *i = *head, *new_head = NULL;
    while (i) {
        if (new_head == NULL) new_head = i;    

        if (i->next != NULL) {
            i->val       = i->val ^ i->next->val;
            i->next->val = i->val ^ i->next->val; 
            i->val       = i->val ^ i->next->val;
            
            i = i->next->next;
        }
        else
            i = i->next;
   }

    return new_head;
}


typedef struct node {
    int val;
    struct node* next;
} node ;

void insert(node** head, int value) {
    node* newNode = malloc(sizeof(node));
    newNode->val = value;
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
    node *l = NULL;

    insert(&l, 1);
    insert(&l, 2);
    insert(&l, 3);

    node *n = swapPairs(&l);

    show(n);

    return 0;
}

