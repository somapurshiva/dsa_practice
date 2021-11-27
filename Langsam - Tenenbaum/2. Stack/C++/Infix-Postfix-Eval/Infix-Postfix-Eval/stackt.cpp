//
//  stackt.cpp
//  Infix-Postfix-Eval
//
//  Created by Shiva Somapur on 05/10/21.
//

#include "stackt.hpp"
#include <iostream>

template <class T> Stack<T>::Stack() {
    top = -1;
    nodes = new T[STACKSIZE];
//    std::cout << "Stack Initialized" << std::endl;
};

template <class T> Stack<T>::~Stack() {
    delete nodes;
};

template <class T> bool Stack<T>::empty(void) {
    return top == -1;
};

template <class T> void Stack<T>::push(T j) {
    if (top == STACKSIZE) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    nodes[++top] = j;
};

template <class T> T Stack<T>::pop(void) {
    T p;
    if (empty()) {
        std::cout << "Stack Underflow" << std::endl;
        return p;
    }
    p = nodes[top--];
    return p;
};

template <class T> T Stack<T>::pop(bool *und) {
    T p;
    if (empty()) {
        *und = true;
        return p;
    }
    *und = false;
    p = nodes[top--];
    return p;
};
