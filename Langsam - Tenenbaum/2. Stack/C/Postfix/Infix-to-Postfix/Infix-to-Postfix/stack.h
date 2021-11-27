//
//  stack.h
//  Infix-to-Postfix
//
//  Created by Shiva Somapur on 05/10/21.
//

#ifndef stack_h
#define stack_h

#endif /* stack_h */

#define STACKSIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int top;
    char items[STACKSIZE];
} STACK;

void initialize(STACK *ps);
int empty(STACK *ps);
char pop(STACK *ps);
void popandtest(STACK *ps, char *px, int *pund);
void push(STACK *ps, char x);
void pushandtest(STACK *ps, char x, int *pover);
