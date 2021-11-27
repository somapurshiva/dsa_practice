//
//  main.c
//  Binary-Tree-Representation
//
//  Created by Shiva Somapur on 20/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define TRUE 1
#define FALSE 0

struct nodetype {
    char info;
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

NODEPTR maketree(char x) {
    NODEPTR p;
    
    p = getnode();
    p->info = x;
    
    p->father = NULL;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}

NODEPTR setleft(NODEPTR p, char x) {
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

NODEPTR setright(NODEPTR p, char x) {
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

void preOrder(NODEPTR p) {
    if (p == NULL)
        return;
    printf("%c", p->info);
    if (p->left != NULL)
        preOrder(p->left);
    if (p->right != NULL)
        preOrder(p->right);
}

void inOrder(NODEPTR p) {
    if (p->left != NULL)
        inOrder(p->left);
    printf("%c", p->info);
    if (p->right != NULL)
        inOrder(p->right);
}

void postOrder(NODEPTR p) {
    if (p->left != NULL)
        postOrder(p->left);
    if (p->right != NULL)
        postOrder(p->right);
    printf("%c", p->info);
}

int main(int argc, const char * argv[]) {
    NODEPTR a,b,c,d,e,f,g,h,i;
    // Build the tree
    a = maketree('A');
    b = setleft(a, 'B');
    d = setleft(b, 'D');
    g = setright(d, 'G');
    c = setright(a, 'C');
    e = setleft(c, 'E');
    f = setright(c, 'F');
    h = setleft(e, 'H');
    i = setright(e, 'I');
    printf("Preorder: ");
    preOrder(a);
    printf("\n");
    
    printf("Inorder: ");
    inOrder(a);
    printf("\n");
    
    printf("Postorder: ");
    postOrder(a);
    printf("\n");
    return 0;
}
