#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* 
 *  Fast and Slow Two Pointers:
 *  ---------------------------
 *  
 *  pointer fast ==> two steps ahead.
 *  pointer slow ==> one step.
 *
 *  if they meet in any where except `null`
 *  then cycle detected.
 *
 *  we need to do Running one time
 *  before starting the comparison,
 *
 *  do {} while ();
 *
 * */



bool hasCycle(node **head) {
    node *slow = *head;
    node *fast = *head;

    do  {
        if (slow) slow = slow->next;
        if (fast) 
            if (fast->next)
                fast = fast->next->next;
            else
                fast = fast->next;
    } while (slow != fast);

    if (slow == NULL && fast == NULL) 
        return false;
    else 
        return true;
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
    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);

    bool ans = hasCycle(&l);

    if (ans) puts("has a cycle");
    else     puts("no cycle");

    return 0;
}

