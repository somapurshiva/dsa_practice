//
//  main.c
//  Binary-Tree-Sort
//
//  Created by Shiva Somapur on 13/11/21.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void) {
    return (NODEPTR) malloc(sizeof(struct node));
}

void freenode(NODEPTR p) {
    free(p);
}

NODEPTR maketree(int i) {
    NODEPTR p;
    
    p = getnode();
    p->info = i;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}

int info(NODEPTR p) {
    return p->info;
}

NODEPTR left(NODEPTR p) {
    return p->left;
}

NODEPTR right(NODEPTR p) {
    return p->right;
}

void setleft(NODEPTR p, int i) {
    NODEPTR q;
    
    q = maketree(i);
    
    p->left = q;
}

void setright(NODEPTR p, int i) {
    NODEPTR q;
    
    q = maketree(i);
    
    p->right = q;
}

void intrav(NODEPTR tree) {
    if (tree != NULL) {
        intrav(tree->left);
        printf("%d ", tree->info);
        intrav(tree->right);
    }
}

NODEPTR preparebst(int x[], int n) {
    NODEPTR tree, p, q;
    tree = maketree(x[0]);
    for (int i = 1; i < n; i++) {
        p = q = tree;
        while (p != NULL) {
            q = p;
            if (x[i] < info(p)) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        // we have reached the leaf node now. At this point, set the x[i] value to either right or left child based on whether it is greater than q or less than q
        if (x[i] < info(q)) {
            setleft(q, x[i]);
        } else
            setright(q, x[i]);
    }
    return tree;
}

void binarytreesort(int x[], int n) {
    NODEPTR tree;
    tree = preparebst(x, n);
    intrav(tree);
}

int main(int argc, const char * argv[]) {
    int x[8] = { 98, 28, 82, 89, 9, 19, 56, 47 };
    binarytreesort(x, 8);
    printf("\n");
    return 0;
}
