//
//  nodetype.h
//  Minimax-Game-Tree
//
//  Created by Shiva Somapur on 10/11/21.
//

#ifndef nodetype_h
#define nodetype_h

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define X 'X'
#define O 'O'
#define BLANK ' '

struct nodetype {
    char board[3][3];
    int turn;
    struct nodetype *son;
    struct nodetype *next;
};

typedef struct nodetype *NODEPTR;

NODEPTR getnode(void) {
    return (NODEPTR) malloc(sizeof(struct nodetype));
}

void freenode(NODEPTR p) {
    free(p);
}

NODEPTR buildtree(char [][3], int);
void expand(NODEPTR, int, int);
NODEPTR generate(char [][3]);
void bestbranch(NODEPTR, char, NODEPTR*, int*);

void nextmove(char brd[][3], int looklevel, char player, char newbrd[][3]) {
    NODEPTR ptree, best;
    int i, j, value;
    
    ptree = buildtree(brd, looklevel);
    bestbranch(ptree, player, &best, &value);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; ++j) {
            newbrd[i][j] = best->board[i][j];
        }
    }
}

NODEPTR buildtree(char brd[][3], int looklevel) {
    NODEPTR ptree;
    int i, j;
    
    ptree = getnode();
    for (i = 0; i < 3; i++)
        for(j = 0; j < 3; ++j)
            ptree->board[i][j] = brd[i][j];
    // Root is a plus node by definition
    ptree->turn = 1;
    ptree->son = NULL;
    ptree->next = NULL;
    // Create the rest of the game tree
    expand(ptree, 0, looklevel);
    return ptree;
}

void expand(NODEPTR p, int plevel, int depth) {
    NODEPTR q;
    
    if (plevel < depth) {
        // p hasn't reached the maximum depth yet
        q = generate(p->board);
        p->son = q;
        while (q != NULL) {
            // Traverse the list of nodes
            if (p->turn == 1)
                q->turn = -1;
            else
                q->turn = 1;
            q->son = NULL;
            expand(q, plevel+1, depth);
            q = q->next;
        }
    }
}

NODEPTR generate(char brd[][3]) {
    int xCount = 0, oCount = 0, i, j, k, l;
    char genChar;
    NODEPTR q, r, first = NULL;
    // Count the Xs and Os
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; ++j)
            if (brd[i][j] == X)
                xCount++;
            else if (brd[i][j] == O)
                oCount++;
    // If both are equal, genrate positions for X
    if (xCount == oCount)
        genChar = X;
    // else generate positions for O
    else
        genChar = O;
    
    // Loop through board, if there is an empty position, generate a new board by copying brd to
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; ++j) {
            if (brd[i][j] == BLANK) {
                // initialize q
                q = getnode();
                q->next = NULL;
                // If it is the first time, make first and r point to this new node
                if (first == NULL)
                    r = first = q;
                else
                    r->next = q;
                for (k = 0; k < 3; k++)
                    for (l = 0; l < 3; ++l) {
                        if (k == i && l == j)
                            q->board[k][l] = genChar;
                        else
                            q->board[k][l] = brd[k][l];
                    }
                r = q;
            }
        }
    return first;
}

int evaluate(char brd[][3], char player) {
    int xVal = 0, oVal = 0;
    char c00 = brd[0][0], c01 = brd[0][1], c02 = brd[0][2];
    char c10 = brd[1][0], c11 = brd[1][1], c12 = brd[1][2];
    char c20 = brd[2][0], c21 = brd[2][1], c22 = brd[2][2];
    
    // Evaluate all the sequences and update the xVal or oVal if valid
    if ((c00 == BLANK) && (c01 == BLANK) && (c02 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c00 == O || c00 == BLANK) && (c01 == O || c01 == BLANK) && (c02 == O || c02 == BLANK))
        oVal++;
    else if ((c00 == X || c00 == BLANK) && (c01 == X || c01 == BLANK) && (c02 == X || c02 == BLANK))
        xVal++;
    if ((c10 == BLANK) && (c11 == BLANK) && (c12 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c10 == O || c10 == BLANK) && (c11 == O || c11 == BLANK) && (c12 == O || c12 == BLANK))
        oVal++;
    else if ((c10 == X || c10 == BLANK) && (c11 == X || c11 == BLANK) && (c12 == X || c12 == BLANK))
        xVal++;
    if ((c20 == BLANK) && (c21 == BLANK) && (c22 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c20 == O || c20 == BLANK) && (c21 == O || c21 == BLANK) && (c22 == O || c22 == BLANK))
        oVal++;
    else if ((c20 == X || c20 == BLANK) && (c21 == X || c21 == BLANK) && (c22 == X || c22 == BLANK))
        xVal++;
    if ((c00 == BLANK) && (c10 == BLANK) && (c20 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c00 == O || c00 == BLANK) && (c10 == O || c10 == BLANK) && (c20 == O || c20 == BLANK))
        oVal++;
    else if ((c00 == X || c00 == BLANK) && (c10 == X || c10 == BLANK) && (c20 == X || c20 == BLANK))
        xVal++;
    if ((c01 == BLANK) && (c11 == BLANK) && (c21 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c01 == O || c01 == BLANK) && (c11 == O || c11 == BLANK) && (c21 == O || c21 == BLANK))
        oVal++;
    else if ((c01 == X || c01 == BLANK) && (c11 == X || c11 == BLANK) && (c21 == X || c21 == BLANK))
        xVal++;
    if ((c02 == BLANK) && (c12 == BLANK) && (c22 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c02 == O || c02 == BLANK) && (c12 == O || c12 == BLANK) && (c22 == O || c22 == BLANK))
        oVal++;
    else if ((c02 == X || c02 == BLANK) && (c12 == X || c12 == BLANK) && (c22 == X || c22 == BLANK))
        xVal++;
    
    // Finally diagonals
    if ((c00 == BLANK) && (c11 == BLANK) && (c22 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c00 == O || c00 == BLANK) && (c11 == O || c11 == BLANK) && (c22 == O || c22 == BLANK))
        oVal++;
    else if ((c00 == X || c00 == BLANK) && (c11 == X || c11 == BLANK) && (c22 == X || c22 == BLANK))
        xVal++;
    if ((c02 == BLANK) && (c11 == BLANK) && (c20 == BLANK)) {
        oVal++;
        xVal++;
    }
    else if ((c02 == O || c02 == BLANK) && (c11 == O || c11 == BLANK) && (c20 == O || c20 == BLANK))
        oVal++;
    else if ((c02 == X || c02 == BLANK) && (c11 == X || c11 == BLANK) && (c20 == X || c20 == BLANK))
        xVal++;
//    printf("xVal= %d, oVal= %d\n",xVal, oVal);
    if (player == X)
        return xVal - oVal;
    else
        return oVal - xVal;
}

void bestbranch(NODEPTR pnd, char player, NODEPTR *pbest, int *pvalue) {
    NODEPTR p, pbest2;
    int val;
    // For leaf node find out the value
    if (pnd->son == NULL) {
        *pvalue = evaluate(pnd->board, player);
        *pbest = pnd;
    } else {
        // This isn't a leaf node. Traverse the list of sons
        p = pnd->son;
        bestbranch(p, player, pbest, pvalue);
        p = *pbest;
        if (pnd->turn == -1)
            *pvalue = -*pvalue;
        p = p->next;
        while (p != NULL) {
            bestbranch(p, player, &pbest2, &val);
            if (pnd->turn == -1)
                val = -val;
            if (val > *pvalue) {
                *pvalue = val;
                *pbest = p;
            }
            p = p->next;
        }
        if (pnd->turn == -1)
            *pvalue = -*pvalue;
    }
}

#endif /* nodetype_h */
