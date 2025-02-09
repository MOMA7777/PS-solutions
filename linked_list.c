#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    int key;
    struct linkedlist * next;
    struct linkedlist * perv;
} node ;

node * sentinel = NULL;

void init() {
    sentinel = malloc(sizeof(node*));

    sentinel->next = sentinel;
    sentinel->perv = sentinel;
}

void insert(int k) {
    node * s   = malloc(sizeof(node*));
    node * new = malloc(sizeof(node*));
    new->key = k;

    s = sentinel;
    while (s->next != sentinel) {
        s = s->next;
    }

    new->next      = sentinel;
    new->perv      = s;
    s->next        = new;
    sentinel->perv = new;
}

void show() {
    node * tmp = malloc(sizeof(node*));

    if (sentinel->next == sentinel) { //equal sign haha
        printf("Empty List\n");
        return;
    }

    tmp = sentinel->next;
    while (tmp->next != sentinel) {
        printf("%d ", tmp->key);

        tmp = tmp->next;
    }
    puts(" ");
}

node * search(int k) {
    if (sentinel->next == sentinel) {
        printf("Empty List");
        return NULL;
    }

    node * tmp = malloc(sizeof(node*));
    tmp = sentinel;

    while (tmp->next != sentinel && tmp->key != k) {
        tmp = tmp->next;
    }

    if (tmp->key == k)
        return tmp;
    else {
        return NULL;
    }
}

void delete(int key) {
    node * s = search(key);

    if (s == NULL) {
        printf("element not in list\n");
        return;
    }

    s->perv->next = s->next;
    s->next->perv = s->perv;
    
    free(s);
}

int main() {
    init();
   
    insert(1); insert(2); insert(3); insert(4);

    show();

    delete(2);

    show();

    return 0;
}
