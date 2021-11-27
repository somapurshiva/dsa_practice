//
//  main.c
//  Huffman-Algo
//
//  Created by Shiva Somapur on 06/11/21.
//

#include <stdio.h>

#define MAXBITS 50
#define MAXSYMBS 50
#define MAXNODES 99 // MAXNODES equals 2*MAXSYMBS-1

#define TRUE 1
#define FALSE 0
#define NULL -1

struct codetype {
    int bits[MAXBITS];
    int startpos;
};

struct nodetype {
    int freq;
    int father; // if node[p] is not a root node, father points to the node's father; if it is, father points to the next root node in the priority queue
    int isleft;
};

void pqinsert(struct nodetype node[], int *rootnodes, int insIdx) {
    int p;
    // For first time just initialize the list
    if (*rootnodes == NULL) {
        *rootnodes = insIdx;
        node[*rootnodes].father = NULL;
        return;
    }
    // First tackle the issue if rootnode has to be updated
    if (node[insIdx].freq < node[*rootnodes].freq) {
        node[insIdx].father = *rootnodes;
        *rootnodes = insIdx;
        return;
    }
    p = *rootnodes;
    while (node[p].father != NULL) {
        if (node[insIdx].freq < node[node[p].father].freq) {
            node[insIdx].father = node[p].father;
            node[p].father = insIdx;
            return;
        }
        p = node[p].father;
    }
    // The passed value is maximum. Append it to the end of the list
    node[p].father = insIdx;
    node[insIdx].father = NULL;
}

void printQ(struct nodetype node[], char alph[], int rootnodes) {
    int p = rootnodes;
    while (p != NULL) {
        printf("(%c, %d) ->", alph[p], node[p].freq);
        p = node[p].father;
    }
}

int pqmindelete(struct nodetype node[], int *rootnodes) {
    int p = *rootnodes;
    *rootnodes = node[*rootnodes].father;
    return p;
}

int main(int argc, const char * argv[]) {
    struct nodetype node[MAXNODES];
    struct codetype cd, code[MAXSYMBS];
    // Initialize rootnodes to zero and set father value as NULL (-1) to help with our min-priority queue impl
    int rootnodes = NULL, i, n, k, p, p1, p2, root, dummy;
    char symb, alph[MAXSYMBS];
    for (i = 0; i < MAXSYMBS; i++)
        alph[i] = ' ';
    printf("Enter N value: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter symbol and frequency: ");
        scanf("%s %d", &symb, &node[i].freq);
        pqinsert(node, &rootnodes, i);
        alph[i] = symb;
    }
//    printQ(node, alph, rootnodes);
//
//    // Play with min del
//    dummy = pqmindelete(node, &rootnodes);
//    printf("Deleted: (%c, %d)\n", alph[dummy], node[dummy].freq);
//    printQ(node, alph, rootnodes);
//
//    dummy = pqmindelete(node, &rootnodes);
//    printf("Deleted: (%c, %d)\n", alph[dummy], node[dummy].freq);
//    printQ(node, alph, rootnodes);
//
//    dummy = pqmindelete(node, &rootnodes);
//    printf("Deleted: (%c, %d)\n", alph[dummy], node[dummy].freq);
//    printQ(node, alph, rootnodes);
//
//    dummy = pqmindelete(node, &rootnodes);
//    printf("Deleted: (%c, %d)\n", alph[dummy], node[dummy].freq);
//    printQ(node, alph, rootnodes);
//
//    printQ(node, alph, rootnodes);
    // Build all the trees now
    for (p = n; p < 2*n-1; p++) {
        // P points to next available node. Obtain the root nodes p1 and p2 with smallest frequencies
        p1 = pqmindelete(node, &rootnodes);
        p2 = pqmindelete(node, &rootnodes);
        // Set left(p) to p1 and right(p) to p2
        node[p1].father = p;
        node[p1].isleft = TRUE;
        node[p2].father = p;
        node[p2].isleft = FALSE;
        node[p].freq = node[p1].freq + node[p2].freq;
        pqinsert(node, &rootnodes, p);
    }
    
    // After the above loop, there should be only one node left with null father field
    root = pqmindelete(node, &rootnodes);
    
    // Extract the codes from the tree
    for (i = 0; i < n; i++) {
        // Initialize code[i]
        cd.startpos = MAXBITS;
        // Travel up the tree till root
        p = i;
        while (p != root) {
            --cd.startpos;
            if (node[p].isleft)
                cd.bits[cd.startpos] = 0;
            else
                cd.bits[cd.startpos] = 1;
            p = node[p].father;
        }
        for (k = cd.startpos; k < MAXBITS; k++)
            code[i].bits[k] = cd.bits[k];
        code[i].startpos = cd.startpos;
    }
    // Print the results
    for (i = 0; i < n; i++) {
        printf("\n%c %d ", alph[i], node[i].freq);
        for (k = code[i].startpos; k < MAXBITS; k++)
            printf("%d", code[i].bits[k]);
        printf("\n");
    }
    return 0;
}
