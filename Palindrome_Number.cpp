#include <bits/stdc++.h>
using namespace std;


/*
 *  reverse the number itself and compare it to the original.
 *
 *  instead of creating string will take O(n) memory and 
 *  not efficient in concatnating.
 *
 * */





class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0, rem = 0, tmp = x;

        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        while (tmp != 0) {
            rem = tmp % 10;
            rev = (rev * 10) + rem;
            tmp /= 10;
        }

        if (x == rev) 
            return true;
        else
            return false;
    }
};






















typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode ;


void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
}

void remove(ListNode*& head, int val) {
    if (!head) return;

    if (head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* temp = head;
    while (temp->next && temp->next->val != val) {
        temp = temp->next;
    }

    if (temp->next) {
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}


void display(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}






int main() {

    node *l = NULL;
    
    insert(l, 1);
    insert(l, 2);
    insert(l, 3);

    display(l);

    return 0;
}
