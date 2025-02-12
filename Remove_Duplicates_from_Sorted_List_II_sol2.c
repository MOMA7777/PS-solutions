// link : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?source=submission-ac

#include <stdio.h>
#include <stdlib.h>

/*
 *  1 - The Ordering of Conditions Matters.
 *   if (i->next != NULL &&       ....     ) !=  
 *   if (     ....       && i->next != NULL) 
 *
 *  2 - Updating and Checking :
 *      
 *      'update then check'
 *      if (i)
 *          i = i->next;
 *
 *      'check then update'
 *      if (i.next != NULL)
 *          i = i->next;
 *
 *
 *  3 - Losing Connection : 
 *      `i` might point to `null`
 *      but unless u didnt also make `cur` point to i or i->next
 *      it will remain point to original list
 *
 *      if (cur) cur->next = NULL
 *
 * */


node * deleteDuplicates(node **head) {
    node *i = *head;
    node *new_head = NULL, *cur = NULL;

    while (i) {
        if (i->next != NULL && i->val == i->next->val) {
            int forbidden = i->val;

            while (i && i->val == forbidden)
                i = i->next;
        }
        else {
            if (new_head == NULL) {
                new_head = i;
                cur = new_head;
            }
            else {
                cur->next = i;
                cur = cur->next;
            }
        
            i = i->next;
        }
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

    node *n = deleteDuplicates(&l);

    show(n);

    return 0;
}

