//
//  main.c
//  Postfix
//
//  Created by Shiva Somapur on 03/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "stack.h"

#define MAXCOLS 80

double eval(char[]);
double oper(int, double, double);

int main(int argc, const char * argv[]) {
    char expr[MAXCOLS];
    int position = 0;
    while ((expr[position++] = getchar()) != '\n');
    expr[--position] = '\0';
    printf("The original postfix expression is: %s\n", expr);
    printf("%f\n", eval(expr));
    return 0;
}

double eval(char expr[]) {
    int c, position;
    double opnd1, opnd2, value;
    STACK opndstk;
    
    opndstk.top = -1;
    for (position = 0; (c = expr[position]) != '\0'; position++) {
        if (isdigit(c)) {
            // Convert the character representation of the digit into double and push it onto the stack
            push(&opndstk, (double) (c - '0'));
        } else {
            opnd2 = pop(&opndstk);
            opnd1 = pop(&opndstk);
            value = oper(c, opnd1, opnd2);
            push(&opndstk, value);
        }
    }
    
    return (pop(&opndstk));
}

double oper(int symb, double op1, double op2) {
    switch (symb) {
        case '+':
            return (op1 + op2);
        case '-':
            return (op1 - op2);
        case '*':
            return (op1 * op2);
        case '/':
            return (op1 / op2);
        case '$':
            return (pow(op1, op2));
        default:
            printf("Illegal Operation");
            exit(1);
    }
}
