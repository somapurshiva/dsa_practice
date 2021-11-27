//
//  stackt.hpp
//  Infix-Postfix-Eval
//
//  Created by Shiva Somapur on 05/10/21.
//

#ifndef stackt_hpp
#define stackt_hpp

#include <stdio.h>
#include <stdlib.h>
//#include <alloc>
//#include <mem>
#include <iostream>

#define STACKSIZE 100

template <class T>
class Stack {
private:
    int top;
    T *nodes;
public:
    Stack();
    bool empty(void);
    void push(T);
    T pop(void);
    T pop(bool *);
    
    ~Stack();
};

#endif /* stackt_hpp */
