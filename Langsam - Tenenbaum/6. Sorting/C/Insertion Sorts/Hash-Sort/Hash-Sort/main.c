//
//  main.c
//  Hash-Sort
//
//  Created by Shiva Somapur on 14/11/21.
//

#include <stdio.h>
#include <stdlib.h>

#define NILL -1

struct node {
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void) {
    return (NODEPTR) malloc(sizeof(struct node));
}

NODEPTR createNode(int info) {
    NODEPTR p;
    
    p = getnode();
    p->info = info;
    p->next = NILL;
    
    return p;
}

void place(NODEPTR *p, int val) {
   NODEPTR q, r, n;
    if (*p == NILL) {
        *p = createNode(val);
    } else {
        r = q = *p;
        while (q != NILL && val > q->info) {
            r = q;
            q = q->next;
        }
        n = createNode(val);
        n->next = q;
        if (q == *p)
            *p = n;
        else
            r->next = n;
    }
}

void addr(int x[], int n) {
    int first, i, j, y;
    NODEPTR f[10] = { NILL, NILL, NILL, NILL, NILL, NILL, NILL, NILL, NILL, NILL }, p;
    
    for (i = 0; i < n; i++) {
        y = x[i];
        // Extract the first digit from the number
        first = y/10;
        place(&f[first], y);
    }
    i = 0;
    for (j = 0; j < 10; j++) {
        p = f[j];
        while (p != NILL) {
            x[i++] = p->info;
            p = p->next;
        }
    }
}

int main(int argc, const char * argv[]) {
    int x[10] = { 25, 57, 48, 37, 12, 92, 31, 86, 39, 33 };
    addr(x, 10);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
