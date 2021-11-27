//
//  main.c
//  Infix-to-Postfix
//
//  Created by Shiva Somapur on 05/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

#define MAXCOLS 80

void postfix(char *, char *);
int prcd(char, char);

int main(int argc, const char * argv[]) {
    char infix[MAXCOLS];
    char postr[MAXCOLS];
    int pos = 0;
    
    while ((infix[pos++] = getchar()) != '\n');
    infix[--pos] = '\0';
    printf("Original infix expression is: %s\n", infix);
    postfix(infix, postr);
    printf("Resultant postfix expression is: %s\n", postr);
    
    return 0;
}

void postfix(char infix[], char postr[]) {
    int position, und;
    int outpos = 0;
    char topsymb = '+';
    char symb;
    STACK opstk;
    opstk.top = -1;
    
    for (position = 0; (symb = infix[position]) != '\0'; position++) {
        if (isalpha(symb)) {
            postr[outpos++] = symb;
        } else {
            popandtest(&opstk, &topsymb, &und);
            while (!und && prcd(topsymb, symb)) {
                postr[outpos++] = topsymb;
                popandtest(&opstk, &topsymb, &und);
            }
            if (!und) {
                push(&opstk, topsymb);
            }
            if (und || (symb != ')')) {
                push(&opstk, symb);
            } else {
                topsymb = pop(&opstk);
            }
        }
    }
    while (!empty(&opstk)) {
        postr[outpos++] = pop(&opstk);
    }
    postr[outpos] = '\0';
}

int prcd(char op1, char op2) {
    if (op1 == '(') return FALSE;
    if (op2 == '(' && op1 != ')') return FALSE;
    if (op2 == ')' && op1 != '(') return TRUE;
    if (op1 == ')') {
        printf("Error in evaluation!");
        exit(1);
    }
    switch (op1) {
        case '$':
        case '*':
        case '/':
            if (op2 == '$') return FALSE;
            else return TRUE;
        case '+':
        case '-':
            if (op2 == '$' || op2 == '/' || op2 == '*') return FALSE;
            else return TRUE;
        default:
            return FALSE;
    }
}
