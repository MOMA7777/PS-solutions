#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
 *  Three Pointers (pervious, current, next)
 *  ----------------------------------------
 *  pervious often treated as dummy point to null at first.
 *
 *  1 - get next.
 *  2 - current --> pervious.
 *  3 - pervious = current.
 *  4 - current = next.
 *
 * */





node *reverseList(node **head) {
    node *cur  = *head;
    node *h    = NULL;

    while (cur != NULL) {
        node *n = cur->next;
        cur->next = h;

        h   = cur;
        cur = n;
    }

    return h;
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

    return 0;
}

