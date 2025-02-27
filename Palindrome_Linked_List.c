#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *  1 - How to reach the middle element in unkown-size data ??
 *      solution : make two pointer 
 *          slow -> first  element.
 *          fast -> second element.
 *
 *      slow will move 1step, fast will move 2steps 
 *      at the end its gurantee slow will be the middle element.
 * */




bool isPalindrome(node **head) {
    node *tmp  = *head; 
    node *slow = *head;
    node *fast = slow->next;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    
    node *h = NULL, *cur = slow->next;
    while (cur) {
        node *nxt = cur->next;
        cur->next = h;

        h   = cur;
        cur = nxt;
    }

    while (h) {
        if (h->val != tmp->val) return false;
        tmp = tmp->next;
        h   = h->next;
    }

    return true;
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
    insert(&l, 2);
    insert(&l, 1);

    bool ans = isPalindrome(&l);

    printf((ans == true) ? "yes\n" : "no\n");

    return 0;
}

