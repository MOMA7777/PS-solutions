#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

















node *reverseBetween(node **head, int left, int right) {
    node *newHead = malloc(sizeof(node));
    newHead->val = -1, newHead->next = *head;
    
    node *t = newHead;
    for(int i = 1; i < left; i++) {
        t = t->next;
    }

    node *p = t, *q = t->next; 
    node *cur = q;
    for(int i = 1; i <= right-left+1; i++) {
        node *nxt = cur->next;
        cur->next = t;

        t   = cur;
        cur = nxt;
    }
    
    p->next = t;
    q->next = cur;

    return newHead->next;
}























typedef struct node {
    int val;
    struct node* next;
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
    node *l = NULL;

    insert(&l, 1);
    insert(&l, 2);
    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);
    insert(&l, 6);
    insert(&l, 7);

    node *ans = reverseBetween(&l, 2, 4);

    show(l);

    return 0;
}

