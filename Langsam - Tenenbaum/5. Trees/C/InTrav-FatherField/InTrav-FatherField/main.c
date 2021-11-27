//
//  main.c
//  InTrav-FatherField
//
//  Created by Shiva Somapur on 23/10/21.
//

#include "nodetype.h"

void intrav4(NODEPTR tree) {
    NODEPTR p, q;
    q = NULL;
    p = tree;
    
    do {
        while (p != NULL) {
            q = p;
            p = p->left;
        }
        if (q != NULL) {
            printf("%c ", q->info);
            p = q->right;
        }
        while (q != NULL && p == NULL) {
            do {
                p = q;
                q = p->father;
            } while (!isleft(p) && q != NULL);
            if (q != NULL) {
                printf("%c ", q->info);
                p = q->right;
            }
        }
    } while (q != NULL);
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
    
    printf("Inorder:\t");
    intrav4(a);
    printf("\n");
    
    return 0;
}
