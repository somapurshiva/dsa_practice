//
//  main.c
//  Stack - C
//
//  Created by Shiva Somapur on 10/02/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

int main(int argc, const char * argv[]) {
    STACK stack;
    int x, pund;
    initialize(&stack);
    popandtest(&stack, &x, &pund);
    if (pund == TRUE) {
        printf("Underflow occured\n");
    }
    push(&stack, 98);
    push(&stack, 28);
    push(&stack, 9828);
    x = pop(&stack);
    printf("Returned Value: %d\n", x);
    printf("Stack State: %d, %d\n", stack.items[1], stack.items[0]);
    return 0;
}
