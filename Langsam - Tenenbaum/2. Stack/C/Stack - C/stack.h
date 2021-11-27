//
//  stack.h
//  Stack - C
//
//  Created by Shiva Somapur on 10/02/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
//

#ifndef stack_h
#define stack_h

#endif /* stack_h */

#define STACKSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int top;
    int items[STACKSIZE];
} STACK;

void initialize(STACK *ps);
int empty(STACK *ps);
int pop(STACK *ps);
void popandtest(STACK *ps, int *px, int *pund);
void push(STACK *ps, int x);
void pushandtest(STACK *ps, int x, int *pover);
