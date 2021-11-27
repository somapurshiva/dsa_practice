//
//  rthreadnode.h
//  InTrav-RThread
//
//  Created by Shiva Somapur on 23/10/21.
//

#ifndef rthreadnode_h
#define rthreadnode_h

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define TRUE 1
#define FALSE 0

struct nodetype {
    char info;
    struct nodetype *left;
    struct nodetype *right;
    int rthread;
};

typedef struct nodetype *NODEPTR;

NODEPTR getnode(void) {
    return malloc(sizeof(struct nodetype));
}

void freenode(NODEPTR p) {
    free(p);
}

NODEPTR maketree(char x) {
    NODEPTR p;
    
    p = getnode();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    p->rthread = TRUE;
    
    return p;
}

NODEPTR setleft(NODEPTR p, char x) {
    NODEPTR q;
    
    if (p == NULL) {
        printf("void insertion");
        exit(1);
    } else if (p->left != NULL) {
        printf("invalid insertion");
        exit(1);
    } else {
        q = getnode();
        q->info = x;
        q->left = NULL;
        p->left = q;
        
        q->right = p;
        q->rthread = TRUE;
        return q;
    }
}

NODEPTR setright(NODEPTR p, char x) {
    NODEPTR q, r;
    if (p == NULL) {
        printf("void insertion");
        exit(1);
    } else if (!p->rthread) {
        printf("invalid insertion");
        exit(1);
    } else {
        q = getnode();
        q->info = x;
        
        r = p->right;
        
        p->right = q;
        p->rthread = FALSE;
        q->left = NULL;
        
        q->right = r;
        q->rthread = TRUE;
        
        return q;
    }
}

#endif /* rthreadnode_h */
