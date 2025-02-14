#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
 *  Fast and Slow Pointers with Simple NOte 
 *  ---------------------------------------
 *
 *  Observation : problem solving is about to analyze
 *  objects behaviours, and Experementing them 
 *
 *  once a cycle detected.
 *  fast and slow has number of decisions, moves, ...
 *
 *
 *  moving : 
 *  fast --> move 3 steps, 2 steps'again', (1 step), stop moving.
 *  slow --> move 3 steps, 2 steps'again', (1 step), stop moving.
 *
 *  posining : 
 *  fast -->  start at the current place, move to fast->next,  (get back to head).
 *  slow --> (start at the current place), move to slow->next, (get back to head).
 *
 *  if fast get back to head, slow stayed
 *  each one move one step 
 *
 *  the next_Position they will met is the cycling node.
 *
 * */



node *hasCycle(node **head) {
    node *tmp_head = *head;
    
    node *slow = *head;
    node *fast = *head;
    do  {
        if (slow) slow = slow->next;
        if (fast) 
            if (fast->next)
                fast = fast->next->next;
            else
                fast = fast->next;

        if (slow == fast) {
            fast = tmp_head;
            
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }

            return slow;
        }

    } while (slow != fast);
    
    return NULL;
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

    insert(&l, 100);
    insert(&l, 2);
    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);
    insert(&l, 6);


    l->next->next->next->next->next = l;

    node *ans = hasCycle(&l);

    if (ans == NULL) puts("no cycle");
    else             printf("%d\n", ans->val);

    return 0;
}

