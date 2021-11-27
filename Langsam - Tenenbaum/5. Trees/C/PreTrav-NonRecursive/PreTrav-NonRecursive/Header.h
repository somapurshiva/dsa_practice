//
//  Header.h
//  PreTrav-NonRecursive
//
//  Created by Shiva Somapur on 23/10/21.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define TRUE 1
#define FALSE 0

struct nodetype {
    int info;
    struct nodetype *left;
    struct nodetype *right;
    struct nodetype *father;
};

typedef struct nodetype *NODEPTR;

NODEPTR getnode(void) {
    return malloc(sizeof(struct nodetype));
}

void freenode(NODEPTR p) {
    free(p);
}

NODEPTR maketree(int x) {
    NODEPTR p;
    
    p = getnode();
    p->info = x;
    
    p->father = NULL;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}

NODEPTR setleft(NODEPTR p, int x) {
    if (p == NULL) {
        printf("Void insertion\n");
    } else if (p->left != NULL) {
        printf("Invalid insertion\n");
    } else {
        p->left = maketree(x);
        p->left->father = p;
        return p->left;
    }
    return NULL;
}

NODEPTR setright(NODEPTR p, int x) {
    if (p == NULL) {
        printf("Void insertion\n");
    } else if (p->right != NULL) {
        printf("Invalid insertion\n");
    } else {
        p->right = maketree(x);
        p->right->father = p;
        return p->right;
    }
    return NULL;
}

#endif /* Header_h */
