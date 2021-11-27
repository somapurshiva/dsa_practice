//
//  stack.c
//  Stack - C
//
//  Created by Shiva Somapur on 10/02/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
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


int pop(STACK *ps) {
    if (empty(ps)) {
        printf("%s", "Stack Underflow!");
        exit(1);
    }
    return (ps->items[ps->top--]);
}

void popandtest(STACK *ps, int *px, int *pund) {
    if (empty(ps)) {
        *pund = TRUE;
        return;
    }
    *pund = FALSE;
    *px = ps->items[ps->top--];
}

void push(STACK *ps, int x) {
    if (ps->top == STACKSIZE - 1) {
        printf("%s", "Stack Overflow!");
        exit(1);
    }
    ps->items[++(ps->top)] = x;
}

void pushandtest(STACK *ps, int x, int *pover) {
    if (ps->top == STACKSIZE - 1) {
        *pover = TRUE;
        return;
    }
    *pover = FALSE;
    ps->items[++(ps->top)] = x;
}
