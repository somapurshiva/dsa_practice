//
//  nodetype.h
//  Josephus-using-Tree
//
//  Created by Shiva Somapur on 07/11/21.
//

#ifndef nodetype_h
#define nodetype_h

#include<stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAXELTS 100 // Maximum number of list elements
#define NUMNODES 2 * MAXELTS - 1
#define BLANKS "                   " // 20 blanks

struct nodetype {
    char info[20];
    int lcount;
    int used;
} node[NUMNODES];

int father(int p) {
    return (p - 1)/2;
}

int left(int p) {
    return 2 * p + 1;
}

int right(int p) {
    return 2 * p + 2;
}

int isLeft(int p) {
    return p % 2 != 0;
}

int setLeftLcount(int p, int lcount) {
    int l = left(p);
    node[l].used = TRUE;
    node[l].lcount = lcount;
    strcpy(node[l].info, BLANKS);
    return l;
}

int setLeftInfo(int p, char info[]) {
    int l = left(p);
    node[l].used = TRUE;
    strcpy(node[l].info, info);
    return l;
}

int setRightLcount(int p, int lcount) {
    int r = right(p);
    node[r].used = TRUE;
    node[r].lcount = lcount;
    strcpy(node[r].info, BLANKS);
    return r;
}

int setRightInfo(int p, char info[]) {
    int r = right(p);
    node[r].used = TRUE;
    strcpy(node[r].info, info);
    return r;
}

int findelement(int k) {
    int p = 0, r = k;
    while (strcmp(node[p].info, BLANKS) == 0) {
        if (r <= node[p].lcount) {
            p = left(p);
        } else {
            r -= node[p].lcount;
            p = right(p);
        }
    }
    return p;
}

void delete(int p) {
    int b, f, q;
    
    if (p == 0) {
        node[p].used = FALSE;
    } else {
        // Choose node's father
        f = father(p);
        // Choose node's brother as well
        if (isLeft(p)) {
            b = right(f);
            // As left node is getting deleted, the lcount value can be reduced from father node
            --node[f].lcount;
        } else
            b = left(p);
        // Once the brother is chosen, check if the brother is a left node. If so, it can be moved to replace the father node
        if (strcmp(node[b].info, BLANKS) != 0) {
            strcpy(node[f].info, node[b].info);
            node[b].used = FALSE;
        }
        // Mark the requested node as unused to delete it
        node[p].used = FALSE;
        // Repeat the exercise to cleanup from the father node till root to either reduce lcount or replace non leaf node with leaf if one sibling is missing
        
        q = f;
        // Repeat the exercvise till we reach the root node
        while (q != 0) {
            // Choose next father and brother
            f = father(q);
            if (isLeft(q)) {
                // For left node, reduce the lcount in father
                --node[f].lcount;
                b = right(f);
            } else
                b = left(f);
            // if the brother is unused (null) and node in question is non-leaf, it can be moved to it's father's place
            if (!node[b].used && strcmp(node[q].info, BLANKS) != 0) {
                strcpy(node[f].info, node[q].info);
                node[q].used = FALSE;
            }
            q = f;
        }
    }
}

void buildtree(int n) {
    int f, i, p, power, size;
    // Set power = 2^d such the 2^d is the smallest number greater than or equal to n. "d" will be the depth of the binary tree
    power = 1;
    while (power < n) {
        power *= 2;
    }
    size = 2 * n - 1;
    
    // Capture the first set of leaf nodes at the deepest level
    for (i = power - 1; i < size; i++) {
        printf("Enter next item: ");
        scanf("%s", &node[i].info);
        node[i].used = TRUE;
    }
    for (i = n - 1; i < power - 1; i++) {
        printf("Enter next item: ");
        scanf("%s", &node[i].info);
        node[i].used = TRUE;
    }
    // The remaining nodes are non-leaf nodes; set their lcounts to zero
    for (i=0; i < n - 1; i++) {
        node[i].used = TRUE;
        node[i].lcount = 0;
        strcpy(node[i].info, BLANKS);
    }
    // Update all the lcounts by traversing up to the root from all the leaves
    for (i = n - 1; i < size; i++) {
        p = i;
        while (p != 0) {
            f = father(p);
            if (isLeft(p))
                ++node[f].lcount;
            p = f;
        }
    }
}

#endif /* nodetype_h */
