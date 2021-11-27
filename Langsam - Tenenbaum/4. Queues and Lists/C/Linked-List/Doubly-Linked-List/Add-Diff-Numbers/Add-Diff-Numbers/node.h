//
//  node.h
//  Add-Diff-Numbers
//
//  Created by Shiva Somapur on 17/10/21.
//

#ifndef node_h
#define node_h

#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct node {
    int info;
    struct node *left, *right;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void) {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}

void freenode(NODEPTR p) {
    free(p);
}

void delete(NODEPTR p, int *px) {
    NODEPTR q, r;
    if (p == NULL) {
        printf("Void deletion\n");
        return;
    }
    *px = p->info;
    q = p->left;
    r = p->right;
    q->right = r;
    r->left = q;
    freenode(p);
    return;
}

void insertright(NODEPTR p, int x) {
    NODEPTR q, r;
    if (p == NULL) {
        printf("Void insertion\n");
        return;
    }
    q = getnode();
    q->info = x;
    r = p->right;
    r->left = q;
    q->right = r;
    q->left = p;
    p->right = q;
    return;
}

void insertleft(NODEPTR p, int x) {
    NODEPTR q, l;
    if (p == NULL) {
        printf("Void insertion\n");
        return;
    }
    q = getnode();
    q->info = x;
    l = p->left;
    l->right = q;
    q->left = l;
    q->right = p;
    p->left = q;
    return;
}

#endif /* node_h */
