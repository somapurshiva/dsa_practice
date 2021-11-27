//
//  main.c
//  Binary-Tree-Traversal
//
//  Created by Shiva Somapur on 23/10/21.
//

#include "nodetype.h"

void pretrav(NODEPTR tree) {
    if (tree != NULL) {
        // First print root, then go left, then go right
        printf("%c ", tree->info);
        pretrav(tree->left);
        pretrav(tree->right);
    }
}

void intrav(NODEPTR tree) {
    if (tree != NULL) {
        // First left, then root, then right
        intrav(tree->left);
        printf("%c ", tree->info);
        intrav(tree->right);
    }
}

void posttrav(NODEPTR tree) {
    if (tree != NULL) {
        // First left, then right, finally root
        posttrav(tree->left);
        posttrav(tree->right);
        printf("%c ", tree->info);
    }
}

int main(int argc, const char * argv[]) {
    NODEPTR a,b,c,d,e,f,g,h,i,j,k,l;
    a = maketree('A');
    b = setleft(a, 'B');
    c = setleft(b, 'C');
    d = setright(b, 'D');
    e = setleft(c, 'E');
    f = setright(c, 'F');
    g = setleft(d, 'G');
    h = setright(d, 'H');
    i = setright(e, 'I');
    j = setright(f, 'J');
    k = setleft(h, 'K');
    l = setright(h, 'L');
    printf("Preorder:\t");
    pretrav(a);
    printf("\n");
    
    printf("Inorder:\t");
    intrav(a);
    printf("\n");
    
    printf("Postorder:\t");
    posttrav(a);
    printf("\n");
    return 0;
}
