//
//  main.c
//  Stack-Linked-List
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
    NODEPTR top;
};

int empty(struct stack *ps) {
    return ps->top == NULL ? TRUE : FALSE;
}

void push(struct stack *ps, int x) {
    NODEPTR p;
    p = getnode();
    p->info = x;
    p->next = ps->top;
    ps->top = p;
}

int pop(struct stack *ps) {
    NODEPTR p;
    int x;
    if (empty(ps)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    p = ps->top;
    ps->top = p->next;
    x = p->info;
    freenode(p);
    return x;
}

void printStack(struct stack *ps) {
    NODEPTR p;
    p = ps->top;
    printf("Printing Stack!!\n");
    while (p != NULL) {
        printf("%d\n", p->info);
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {
    struct stack s;
    // Initialize the Stack
    s.top = NULL;
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
