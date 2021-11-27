//
//  routine.h
//  Infix-Postfix-Eval
//
//  Created by Shiva Somapur on 05/10/21.
//

#ifndef routine_h
#define routine_h
#include "stackt.cpp"
#include <math.h>

#define MAXCOLS 52

void postfix(char *infix, char *postr);
bool prcd(char op1, char op2);
bool isoperand(char op);
bool isoperator(char op);

long double eval(char *postr);
long double oper(int symb, long double op1, long double op2);

bool prcd(char op1, char op2) {
    if (op1 == '[') return false;
        if (op2 == '[' && op1 != ']') return false;
        if (op2 == ']' && op1 != '[') return true;
        if (op1 == ']') {
            printf("Error in evaluation!");
            exit(1);
        }
        switch (op1) {
            case '$':
            case '*':
            case '/':
                if (op2 == '$') return false;
                else return true;
            case '+':
            case '-':
                if (op2 == '$' || op2 == '/' || op2 == '*') return false;
                else return true;
            default:
                return false;
        }
}

bool isoperator(char op) {
    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
            return true;
        default:
            return false;
    }
}

bool isoperand(char op) {
    if (op >= '0' && op <= '9') return true;
    return false;
}

void postfix(char *infix, char *postr) {
    int position;
    bool und;
    int outpos = 0;
    char topsymb = '+';
    char symb;
    Stack<char> opstk;// = new Stack<char>();
    
    for (position = 0; (symb = infix[position]) != '\0'; position++) {
        if (isoperand(symb)) {
            postr[outpos++] = symb;
//            std::cout << postr << std::endl;
        } else {
            topsymb = opstk.pop(&und);
            while (!und && prcd(topsymb, symb)) {
                postr[outpos++] = topsymb;
                topsymb = opstk.pop(&und);
            }
            if (!und)
                opstk.push(topsymb);
            if (und || (symb != ']'))
                opstk.push(symb);
            else
                topsymb = opstk.pop();
        }
    }
    while (!opstk.empty()) {
        postr[outpos++] = opstk.pop();
    }
    postr[outpos] = '\0';
}

long double oper(int symb, long double op1, long double op2) {
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
            std::cout << "Illegal Operation" << std::endl;
            exit(1);
    }
}

long double eval(char *postr) {
    int c, position;
    long double opnd1, opnd2, value;
    Stack<long double> opndstk;
    
    for (position = 0; (c = postr[position]) != '\0'; position++) {
        if (isoperand(c)) {
            long double val = c - '0';
            opndstk.push(val);
        } else {
            opnd2 = opndstk.pop();
            opnd1 = opndstk.pop();
            value = oper(c, opnd1, opnd2);
            opndstk.push(value);
        }
    }
    return opndstk.pop();
}

#endif /* routine_h */
