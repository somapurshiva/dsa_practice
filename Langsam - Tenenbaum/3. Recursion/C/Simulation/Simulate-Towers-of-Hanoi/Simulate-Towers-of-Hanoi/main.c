//
//  main.c
//  Simulate-Towers-of-Hanoi
//
//  Created by Shiva Somapur on 09/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 50
#define TRUE 1
#define FALSE 0

struct dataarea {
    int nparam;
    char fromparam;
    char toparam;
    char auxparam;
};

struct stack {
    int top;
    struct dataarea item[MAXSTACK];
};

void popandtest(struct stack *ps, struct dataarea *parea, short int *und) {
    struct dataarea local;
    if (ps->top == -1) {
        *und = TRUE;
        return;
    }
    *und = FALSE;
    local = ps->item[ps->top--];
    parea->nparam = local.nparam;
    parea->fromparam = local.fromparam;
    parea->toparam = local.toparam;
    parea->auxparam = local.auxparam;
}

void push(struct stack *s, struct dataarea *d) {
    if (s->top == MAXSTACK - 1) {
        printf("Error! Stack Overflow\n");
        exit(1);
    }
    s->item[++s->top] = *d;
}

void simtowers(int n, char frompeg, char topeg, char auxpeg) {
    struct stack s;
    struct dataarea currarea;
    short int und;
    char temp;
    
    s.top = -1;
    currarea.nparam = n;
    currarea.fromparam = frompeg;
    currarea.toparam = topeg;
    currarea.auxparam = auxpeg;
    
    while (TRUE) {
        while (currarea.nparam != 1) {
            push(&s, &currarea);
            --currarea.nparam;
            temp = currarea.toparam;
            currarea.toparam = currarea.auxparam;
            currarea.auxparam = temp;
        }
        printf("\nMove disk 1 from peg %c to peg %c", currarea.fromparam, currarea.toparam);
        popandtest(&s, &currarea, &und);
        if (und == TRUE)
            return;
        printf("\nMove disk %d from peg %c to peg %c", currarea.nparam, currarea.fromparam, currarea.toparam);
        --currarea.nparam;
        temp = currarea.fromparam;
        currarea.fromparam = currarea.auxparam;
        currarea.auxparam = temp;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    simtowers(n, 'A', 'B', 'C');
    printf("\n");
    return 0;
}
