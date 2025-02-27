#include <bits/stdc++.h>
using namespace std;





/*
 *  mergin intervals 
 *  ----------------
 *  1 - divide the interval into two halves.
 *  2 - reverse the second interval.
 *
 *  3 - merge both:
 *      let first ==> left, second ==> from right.
 *      
 *      take next of each one <t1 and t2>.
 *      make first point to second before updating
 *      make second point to t1
 *
 *      update first  = t1
 *      update second = t2.
 *
 *      do that until second->next != NULL
 *      cause the first one's null will be end of original list.
 * */


class Solution {
public:
    void reorderList(node **head) {
        node *fast = *head, *slow = *head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        node *prev = NULL, *cur = slow, *nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        node *first = *head, *second = perv;
        while (second->next) {
            node *t1 = first->next, *t2 = second->next;

            first->next  = second;
            second->next = t1;

            first  = t1;
            second = t2;
        }
    }
};


typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} node ;





void insert(node** head, int value) {
    node* newNode = new node;
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
    Solution mySol;
     
    node *l;
    insert(&l, 1);
    insert(&l, 2);
    insert(&l, 3);
    insert(&l, 4);
    insert(&l, 5);

    mySol.reorderList(&l);

    show(l);

    return 0;
}

