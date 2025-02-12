#include <stdio.h>
#include <stdlib.h>


/* 
 *  Two pointer solution would work with only the problem case 
 *  so its designed for it, which might be great advantage 'or not'.
 *
 *  When one Set's size is bigger than the other two pointer 
 *  solution would work.
 *
 * */


node * getIntersectionNode(node **headA, node **headB) {
    node *hi = headA, *hj = headB;
    set<node*> listA; 

    for(node *i = hi; i != NULL; i = i->next) {
        listA.insert(i);
    }

    for(node *j = hj; j != NULL; j = j->next) {
        if (listA.find(j) != listA.end()) return j;
    }

    return NULL;
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
    node *l = NULL, *r = NULL;
    
    node *intersect = malloc(sizeof(node));
    intersect->val  = 100;
    intersect->next = NULL;
    
    insert(&l, 1);
    insert(&l, 2);
    insert(&r, 3);
    insert(&r, 4);
   
    l->next->next = intersect;
    r->next->next = intersect;

    insert(&intersect, 20);
    insert(&intersect, 30);
    insert(&intersect, 40);

    show(l);
    show(r);

    node *ans = getIntersectionNode(&l, &r);    

    if (ans == NULL) puts("no intersection");
    else             printf("%d\n", intersect->val);
    return 0;
}

