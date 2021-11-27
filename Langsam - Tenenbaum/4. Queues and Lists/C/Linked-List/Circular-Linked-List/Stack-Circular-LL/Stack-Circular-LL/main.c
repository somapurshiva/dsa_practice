//
//  main.c
//  Stack-Circular-LL
//
//  Created by Shiva Somapur on 17/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define TRUE 1
#define FALSE 0

struct node {
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void) {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}

void freenode(NODEPTR p) {
    free(p);
}

struct stack {
    NODEPTR last;
};

int empty(struct stack *ps) {
    return ps->last == NULL ? TRUE : FALSE;
}

void push(struct stack *ps, int x) {
    NODEPTR p;
    
    p = getnode();
    p->info = x;
    if(empty(ps)) {
        ps->last = p;
    } else {
        p->next = ps->last->next;
    }
    ps->last->next = p;
}

int pop(struct stack *ps) {
    NODEPTR p;
    int x;
    if (empty(ps)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    p = ps->last->next;
    x = p->info;
    if (ps->last == p)
        ps->last = NULL;
    else
        ps->last->next = p->next;
    freenode(p);
    return x;
}

void printStack(struct stack *ps) {
    NODEPTR p;
    if (ps->last == NULL) {
        printf("Empty Stack\n");
        return;
    }
    p = ps->last->next;
    do {
        printf("%d\n", p->info);
        p = p->next;
    } while (ps->last->next != p);
}

int main(int argc, const char * argv[]) {
    struct stack s;
    // Initialize the Stack
    s.last = NULL;
//    printf("Pop: %d", pop(&s));
    push(&s, 98);
    push(&s, 28);
    push(&s, 82);
    push(&s, 89);
    push(&s, 124);
    printStack(&s);
    // Pop two elements
    printf("Popped: %d\n",pop(&s));
    printf("Popped: %d\n",pop(&s));
    printStack(&s);
    return 0;
}
