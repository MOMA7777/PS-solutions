#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>










node *removeElements(node **head, int data) {
    node *tmp = *head;
    node *newHead = NULL, *cur = NULL;

    while (tmp) {
        if (tmp->val == data) {
            while (tmp != NULL && tmp->val == data) 
                tmp = tmp->next;
        }
        else {
            if (newHead == NULL) {
                newHead = tmp;
                cur = newHead;
            }
            else {
                cur->next = tmp;
                cur = cur->next;
            }
            tmp = tmp->next;
        }
    }

    if (cur) cur->next = NULL;

    return newHead;
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
    node *l = NULL, *r = NULL;

    insert(&l, 1);
    insert(&l, 2);
    insert(&l, 6);
    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);
    insert(&l, 6);
    
    node *ans = removeElements(&l, 6);

    show(ans);

    return 0;
}

