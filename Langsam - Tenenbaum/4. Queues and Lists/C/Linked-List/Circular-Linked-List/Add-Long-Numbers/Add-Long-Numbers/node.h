//
//  node.h
//  Add-Long-Numbers
//
//  Created by Shiva Somapur on 17/10/21.
//

#ifndef node_h
#define node_h

#include <stdlib.h>

struct node {
    int info;
    struct node *next;
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

void insafter(NODEPTR s, int number) {
    NODEPTR p = getnode();
    p->info = number;
    p->next = s->next;
    s->next = p;
}

#endif /* node_h */
