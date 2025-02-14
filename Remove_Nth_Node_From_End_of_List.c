#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Fast and Slow pointers
 * ----------------------
 *
 *  Removing the second element from the left that's easy. 
 *  but Removing the second element from the right is tricky and u dont know Size.
 *
 *  left  ==> Move sequential, linear until ur counter reach 2 then remove it.
 *  right ==> Move with two different steps,
 *
 *  one is fast, one is slow
 *
 *  fast will go first and once it reach 2'st element
 *  
 *  once fast reached the second element, 
 *  BOTH will move simulatounsly until the end.
 *
 *  once fast(went first) reach the end slow(went second) will be at the position
 *  with equlivant to 2'st but from the right.
 *
 *
 *
 *
 *     s     f             
 *        1  2  3  4  5
 *
 *        s     f             
 *        1  2  3  4  5
 *
 *           s     f             
 *        1  2  3  4  5
 *
 *              s     f          
 *        1  2  3  4  5             s.next = target element!
 *        --------------------------------------------------
 *
 *        s.next = s.next.next               now REMOVED!
 *
 * */


node *removeNthFromEnd(node **head, int n) {
    node *dummy = malloc(sizeof(node));
    dummy->val  = 0;
    dummy->next = *head;

    node *fast = dummy;
    node *slow = dummy;

    int i = 0;
    while (i != n) {
       fast = fast->next;
       i++;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
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

    node *n = removeNthFromEnd(&l, 3);

    show(n);

    return 0;
}

