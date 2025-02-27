#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*
 *  Guessing Game!
 *
 * */

node *partition(node **head, int x) {
    node *insertafter = NULL, *newHead = NULL;
    node *i = malloc(sizeof(node));
    i->next = *head;
    i->val  = -1;
    
    newHead = i;

    while (i->next) {
        if (i->next->val >= x && insertafter == NULL) {
            insertafter = i;        
        }

        if (i->next->val < x && insertafter != NULL) {
            node *nxt = i->next->next;

            i->next->next     = insertafter->next;
            insertafter->next = i->next;
            insertafter       = insertafter->next;
            
            i->next = nxt;
            continue;
        }

        i = i->next;
    }

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

    insert(&l, 2);
    insert(&l, 1);

    show(l);

    int x = 2;
    node *ans = partition(&l, x);
    
    show(ans);

    return 0;
}

