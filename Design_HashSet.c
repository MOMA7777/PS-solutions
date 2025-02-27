#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




/*
 *  dont take this solution seriously.
 *
 *  not collision will happen cause HashSet size 
 *  is upper than keys's possible values.
 *
 * */





#define maxHashSize 10000000 
#define ll long long

typedef struct {
    ll HashSetArray[maxHashSize];    
} MyHashSet;

ll hash_function(int key) {
    return key % maxHashSize;
}

void store(MyHashSet **obj, int hash_value) {
    ll index = hash_value % maxHashSize;
    (*obj)->HashSetArray[index] = hash_value;
}

MyHashSet* myHashSetCreate() {
   MyHashSet * HashSet = malloc(sizeof(MyHashSet));

   return HashSet;
}

void myHashSetAdd(MyHashSet **obj, int key) {
    ll hash_value = hash_function(key);
    store(obj, hash_value);
}

void myHashSetRemove(MyHashSet **obj, int key) {
    ll hash_value = hash_function(key);
    ll index = hash_value % maxHashSize;

    if ((*obj)->HashSetArray[index]) 
        (*obj)->HashSetArray[index] = 0;
}

bool myHashSetContains(MyHashSet **obj, int key) {
    ll hash_value = hash_function(key);
    ll index = hash_value % maxHashSize;

    if ((*obj)->HashSetArray[index]) 
        return true;
    else 
        return false;
}

void myHashSetFree(MyHashSet **obj) {
    free(*obj);
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
    MyHashSet * s = myHashSetCreate();

    myHashSetAdd(&s, 1);
    myHashSetAdd(&s, 2);
    myHashSetAdd(&s, 3);

    printf("%d\n", myHashSetContains(&s, 1));
    printf("%d\n", myHashSetContains(&s, 2));
    printf("%d\n", myHashSetContains(&s, 4));
    printf("%d\n", myHashSetContains(&s, 3));
    printf("%d\n", myHashSetContains(&s, 6));

    myHashSetFree(&s);

    return 0;
}

