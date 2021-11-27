//
//  stack.c
//  Infix-to-Postfix
//
//  Created by Shiva Somapur on 05/10/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void initialize(STACK *ps) {
    ps->top = -1;
}

int empty(STACK *ps) {
    if (ps->top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

char pop(STACK *ps) {
    if (empty(ps)) {
        printf("%s", "Stack Underflow!");
        exit(1);
    }
    return (ps->items[ps->top--]);
}

void popandtest(STACK *ps, char *px, int *pund) {
    if (empty(ps)) {
        *pund = TRUE;
        return;
    }
    *pund = FALSE;
    *px = ps->items[ps->top--];
}

void push(STACK *ps, char x) {
    if (ps->top == STACKSIZE - 1) {
        printf("%s", "Stack Overflow!");
        exit(1);
    }
    ps->items[++(ps->top)] = x;
}

void pushandtest(STACK *ps, char x, int *pover) {
    if (ps->top == STACKSIZE - 1) {
        *pover = TRUE;
        return;
    }
    *pover = FALSE;
    ps->items[++(ps->top)] = x;
}
