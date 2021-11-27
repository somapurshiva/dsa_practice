//
//  main.c
//  Simulate-Factorial-Non-Recursion
//
//  Created by Shiva Somapur on 09/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 50

struct dataarea {
    int param;
    int x;
    long int y;
    short int retaddr;
};

struct stack {
    int top;
    struct dataarea item[MAXSTACK];
};

void push(struct stack *s, struct dataarea *d) {
    if (s->top == MAXSTACK - 1) {
        printf("Error! Stack Overflow\n");
        exit(1);
    }
    s->item[++s->top] = *d;
}

void popsub(struct stack *ps, struct dataarea *parea) {
    struct dataarea local;
    if (ps->top == -1) {
        printf("Error! Stack Underflow\n");
        exit(1);
    }
    local = ps->item[ps->top--];
    parea->param = local.param;
    parea->retaddr = local.retaddr;
    parea->x = local.x;
    parea->y = local.y;
}

long int simfact(int n) {
    struct dataarea currarea;
    struct stack s;
    short int i;
    long int result;
    
    // Initialize
    s.top = -1;
    // Initialize a dummy data area
    currarea.param = 0;
    currarea.x = 0;
    currarea.y = 0;
    currarea.retaddr = 0;
    // Push dummy data area onto stack
    push(&s, &currarea);
    
    // Set param and ret addr of current data area to proper values
    currarea.param = n;
    currarea.retaddr = 1;
start: // Beginning of the simulated factorial routine
    if (currarea.param == 0) {
        // Simulation of return (1)
        result = 1;
        i = currarea.retaddr;
        // Before returning pop out the last currarea from stack
        popsub(&s, &currarea);
        switch (i) {
            case 1: goto label1;
            case 2: goto label2;
        }
    }
    currarea.x = currarea.param - 1;
    // Simulation of recursive call to factorial function after decrementing input
    push(&s, &currarea);
    currarea.param = currarea.x;
    currarea.retaddr = 2;
    goto start;
label2: // The point to which we return from the recursive call. Set currarea.y to returned value.
    currarea.y = result;
    // Simulation of return(n*y)
    result = currarea.param * currarea.y;
    i = currarea.retaddr;
    popsub(&s, &currarea);
    switch (i) {
        case 1: goto label1;
        case 2: goto label2;
    }
label1: // Returning to the main routine here
    return result;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    printf("Key in the n value: ");
    scanf("%d", &n);
    printf("Factorial value = %ld\n", simfact(n));
    return 0;
}
