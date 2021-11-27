//
//  main.c
//  InTrav-RThread
//
//  Created by Shiva Somapur on 23/10/21.
//

#include "rthreadnode.h"

void intrav3(NODEPTR tree) {
    NODEPTR p, q;
    p = tree;
    do {
        q = NULL;
        // Traverse on the Left leg of the tree unless you find a NULL left leg
        while (p != NULL) {
            q = p;
            p = p->left;
        }
        // Once you reach the NULL left leg, print the root
        if (q != NULL) {
            printf("%c ", q->info);
            // Now go to the right leg
            p = q->right;
            // Once on the right leg, again traverse on it's left leg till you reach NULL (top while loop will take care)
            // If you have reached a leaf node (identified by rthread), print root value again which p will be now pointing to
            while (q->rthread && p != NULL) {
                printf("%c ", p->info);
                q = p;
                p = p->right;
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
    
    printf("Inorder: ");
    intrav3(a);
    printf("\n");
    
    return 0;
}
