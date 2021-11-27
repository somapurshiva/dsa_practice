//
//  main.c
//  PreTrav-NonRecursive
//
//  Created by Shiva Somapur on 23/10/21.
//

#include "Header.h"

#define MAXNODES 100

struct stack {
    int top;
    NODEPTR items[MAXNODES];
};

int empty(struct stack *ps) {
    return ps->top == -1 ? TRUE : FALSE;
}

void push(struct stack *ps, NODEPTR p) {
    if (ps->top >= MAXNODES) {
        printf("Stack Overflow!!!\n");
        exit(1);
    } else {
        ps->items[++ps->top] = p;
    }
}

NODEPTR pop(struct stack *ps) {
    if (empty(ps)) {
        printf("Stack Underflow!!!\n");
        exit(1);
    } else {
        return ps->items[ps->top--];
    }
}


void pretrav(NODEPTR tree) {
    struct stack s;
    s.top = -1;
    NODEPTR p = tree;
    
    do {
        while (p != NULL) {
            printf("%c ", p->info);
            push(&s, p);
            p = p->left;
        }
        if (!empty(&s)) {
            p = pop(&s);
            p = p->right;
        }
    } while (!empty(&s) || p != NULL);
}

void intrav(NODEPTR tree) {
    struct stack s;
    s.top = -1;
    NODEPTR p = tree;
    
    do {
        while (p != NULL) {
            push(&s, p);
            p = p->left;
        }
        if (!empty(&s)) {
            p = pop(&s);
            printf("%c ", p->info);
            p = p->right;
        }
    } while (!empty(&s) || p != NULL);
}

void posttrav(NODEPTR tree) {
    struct stack ins, outs;
    ins.top = outs.top = -1;
    NODEPTR p = tree;
    push(&ins, p);
    while (!empty(&ins)) {
        p = pop(&ins);
        push(&outs, p);
        if (p->left != NULL)
            push(&ins, p->left);
        if (p->right != NULL)
            push(&ins, p->right);
    }
    while (!empty(&outs)) {
        printf("%c ", pop(&outs)->info);
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
