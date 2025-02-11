#include <stdio.h>
#include <stdlib.h>

/*
 *  three Pointers approach:-
 *  1 - original list iteration (i)
 *  2 - our conditions list iteration (cur)
 *  3 - head of our conditions list (new_head)
 *
 * */

node * deleteDuplicates(node **head) {
    int freq[1000] = {0};

    node *i = *head;
    while (i) {
        freq[i->val+100]++;
        i = i->next;
    }

    i = *head;
    node *new_head = NULL, *cur = NULL;
    while (i) {
        if (freq[i->val+100] == 1) { 
           if (new_head == NULL) {
                new_head = i;
                cur = new_head;
           }
           else {
            cur->next = i;
            cur = cur->next;
           }
        }
        
        i = i->next;
    }

    if (cur) cur->next = NULL;

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
    insert(&l, 2);
    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);
    insert(&l, 5);
    insert(&l, 6);

    show(l);

    node *n = deleteDuplicates(&l);

    show(n);

    return 0;
}

