//
//  main.c
//  Quick-Sort
//
//  Created by Shiva Somapur on 12/11/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 20
#define TRUE 1
#define FALSE 0

void partition(int x[], int lb, int ub, int *pj) {
    int a, down, up, temp;
    
    // a is the element whose final position is sought
    a = x[lb];
    
    up = ub;
    down = lb;
    while (down < up) {
        while (x[down] <= a && down < ub) {
            down++;
        }
        while (x[up] > a) {
            up--;
        }
        // If the pointers haven't crossed each other, time to interchange the two elements
        if (down < up) {
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    // When the while loop ends, x[up] is interchanged with x[lb] and the posititon of up is set to the j pointer
    x[lb] = x[up];
    x[up] = a;
    *pj = up;
}

void quick(int x[], int lb, int ub) {
    int j;
    // For single element, lb will be equal to ub
    if (lb >= ub)
        return;
    
    partition(x, lb, ub, &j);
    // After above call x[j]'s position will be fixed. It will be at its final position
    // Recursively call the other two arrays to sort them
    quick(x, lb, j-1);
    quick(x, j+1, ub);
}

struct bndtype {
    int lb;
    int ub;
};
// Stack to store the bound values for each recursive call
struct stack {
    int top;
    struct bndtype bounds[MAXSTACK];
};

int empty(struct stack *ps) {
    return ps->top == -1;
}

void push(struct stack *ps, struct bndtype *pbndtype) {
    if (ps->top == MAXSTACK) {
        printf("Stack Overflow\n");
        exit(1);
    }
    struct bndtype bnd;
    bnd.lb = pbndtype->lb;
    bnd.ub = pbndtype->ub;
    ps->bounds[++ps->top] = bnd;
}

void popsub(struct stack *ps, struct bndtype *pbndtype) {
    if (empty(ps)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct bndtype bnd = ps->bounds[ps->top--];
    pbndtype->lb = bnd.lb;
    pbndtype->ub = bnd.ub;
}

void quicksortstack(int x[], int lb, int ub) {
    int i, j;
    struct stack stack;
    struct bndtype newbnds;
    
    stack.top = -1;
    newbnds.lb = lb;
    newbnds.ub = ub;
    push(&stack, &newbnds);
    // Process till the stack isn't empty
    while (!empty(&stack)) {
        popsub(&stack, &newbnds);
        while (newbnds.ub > newbnds.lb) {
            // Process the next subarray
            partition(x, newbnds.lb, newbnds.ub, &j);
            // At this point, stack the larger subarray and process the smaller subarray in next iteration
            if (j - newbnds.lb > newbnds.ub - j) {
                // Lower sub array is the larger one. So it will go into stack
                // i is the temp variable that will hold the upper bound here and lower bound in else block
                i = newbnds.ub;
                newbnds.ub = j-1;
                push(&stack, &newbnds);
                // Reset the bounds to point to upper sub array
                newbnds.lb = j + 1;
                newbnds.ub = i;
            } else {
                i = newbnds.lb;
                newbnds.lb = j + 1;
                push(&stack, &newbnds);
                newbnds.lb = i;
                newbnds.ub = j - 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int x[8] = { 25, 57, 48, 37, 12, 92, 86, 33 };
    int i;
    
//    quick(x, 0, 7);
    quicksortstack(x, 0, 7);
    
    for (i = 0; i < 8; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
