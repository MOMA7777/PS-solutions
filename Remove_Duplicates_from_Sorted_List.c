/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
node * deleteDuplicates(node * head) {
    node *i = head;

    while (i != NULL && i->next != NULL) {
        if (i->val == i->next->val) {
            i->next = i->next->next;
        }
        else {
            i = i->next;
        }
    }

    return head;
}
