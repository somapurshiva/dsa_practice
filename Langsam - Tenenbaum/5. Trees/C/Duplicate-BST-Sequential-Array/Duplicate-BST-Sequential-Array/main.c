//
//  main.c
//  Duplicate-BST-Sequential-Array
//
//  Created by Shiva Somapur on 20/10/21.
//

#include <stdio.h>

#define NUMNODES 500
#define TRUE 1
#define FALSE 0

struct nodetype {
    int info;
    int used;
} node[NUMNODES];

void maketree(int x) {
    int p;
    
    node[0].info = x;
    node[0].used = TRUE;
    
    // Mark all nodes as unused
    for (p = 1; p < NUMNODES; p++)
        node[p].used = FALSE;
}

void setleft(int p , int x) {
    int _2p1 = 2 * p + 1;
    if (_2p1 >= NUMNODES)
        printf("Array Overflow\n");
    else if (node[_2p1].used == TRUE)
        printf("Invalid insertion\n");
    else {
        node[_2p1].info = x;
        node[_2p1].used = TRUE;
    }
}

void setright(int p, int x) {
    int _2p2 = 2 * p + 2;
    if (_2p2 >= NUMNODES)
        printf("Array Overflow\n");
    else if (node[_2p2].used == TRUE)
        printf("Invalid insertion\n");
    else {
        node[_2p2].info = x;
        node[_2p2].used = TRUE;
    }
}
    
void preOrder(int p) {
    int _2p1 = 2* p + 1;
    int _2p2 = 2* p + 2;
    if (node[p].used == FALSE)
        return;
    printf("%d - ", node[p].info);
    if (node[_2p1].used == TRUE)
        preOrder(_2p1);
    if (node[_2p2].used == TRUE)
        preOrder(_2p2);
}

int main(int argc, const char * argv[]) {
    int p, q, number, i = 1;
    int arr[] = { 14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5 };
    maketree(arr[0]);
    while (i < 15) {
        number = arr[i];
        p = q = 0;
        while (number != node[p].info && node[q].used == TRUE && q < NUMNODES) {
            p = q;
            if (number < node[p].info)
                q = 2 * p + 1;
            else
                q = 2 * p + 2;
        }
        if (number == node[p].info)
            printf("%d is a duplicate\n", number);
        else if (number < node[p].info)
            setleft(p, number);
        else
            setright(p, number);
        i++;
    }
    preOrder(0);
    return 0;
}
