//
//  treenode.h
//  Ordered-Tree-Expression-Eval
//
//  Created by Shiva Somapur on 09/11/21.
//

#ifndef treenode_h
#define treenode_h

#include <stdio.h>
#include <stdlib.h>

#define NULL 0

#define TRUE 1
#define FALSE 0

#define OPERATOR 0
#define OPERAND 1

union info {
    char oprtr;
    float val;
};

struct treenode {
    short int utype; // OPERATOR or OPERAND
    union info info;
    struct treenode *son;
    struct treenode *next;
};
typedef struct treenode *NODEPTR;

NODEPTR getnode(void) {
    return (NODEPTR) malloc(sizeof(struct treenode));
}

void freenode(NODEPTR p) {
    free(p);
}

float apply(NODEPTR p) {
    float retVal = ((p->son)->info).val;
    NODEPTR q;
    
    switch ((p->info).oprtr) {
        case '+':
            q = (p->son)->next;
            while (q != NULL) {
                retVal += q->info.val;
                q = q->next;
            }
            break;
        case '-':
            q = (p->son)->next;
            retVal -= q->info.val;
            break;
        case '*':
            q = (p->son)->next;
            while (q != NULL) {
                retVal *= p->info.val;
                q = q->next;
            }
            break;
        case '/':
            q = (p->son)->next;
            retVal /= q->info.val;
            break;
        default:
            retVal = 0;
            break;
    }
    return retVal;
}

void setsons(NODEPTR p, NODEPTR list) {
    if (p == NULL) {
        printf("invalid insertion\n");
        exit(1);
    }
    if (p->son != NULL) {
        printf("invalid insertion\n");
        exit(1);
    }
    p->son = list;
}

void addsonVal(NODEPTR p, float x) {
    NODEPTR q, r;
    
    if (p == NULL) {
        printf("void insertion\n");
        exit(1);
    }
    // pointer q traverses the list of sons of p, r is one node behind q
    r = NULL;
    q = p->son;
    
    while (q != NULL) {
        r = q;
        q = q->next;
    }
    // At this point r points to the youngest son of p, or is null if p has no sons
    q = getnode();
    q->utype = OPERAND;
    q->info.val = x;
    q->next = NULL;
    
    // if the previous pointer (r) is NULL, it means that the parent had no son previously
    if (r == NULL)
        p->son = q;
    else
        r->next = q;
}

void addsonOprtr(NODEPTR p, char oprtr) {
    NODEPTR q, r;
    
    if (p == NULL) {
        printf("void insertion\n");
        exit(1);
    }
    // pointer q traverses the list of sons of p, r is one node behind q
    r = NULL;
    q = p->son;
    
    while (q != NULL) {
        r = q;
        q = q->next;
    }
    // At this point r points to the youngest son of p, or is null if p has no sons
    q = getnode();
    q->utype = OPERATOR;
    q->info.oprtr = oprtr;
    q->next = NULL;
    
    // if the previous pointer (r) is NULL, it means that the parent had no son previously
    if (r == NULL)
        p->son = q;
    else
        r->next = q;
}

#endif /* treenode_h */
