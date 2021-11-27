//
//  main.c
//  Path-Transclose
//
//  Created by Shiva Somapur on 21/11/21.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAXNODES 5

void prod (int a[][MAXNODES], int b[][MAXNODES], int c[][MAXNODES]) {
    int i, j, k, val;
    
    // pass through rows
    for (i = 0; i < MAXNODES; ++i)
        // pass through columns
        for (j = 0; j < MAXNODES; ++j) {
            val = FALSE;
            for (k = 0; k < MAXNODES; ++k)
                val = val || (a[i][k] && b[k][j]);
            c[i][j] = val;
        }
}

void transclose (int adj[][MAXNODES], int path[][MAXNODES]) {
    int i, j, k;
    int newprod[MAXNODES][MAXNODES], adjprod[MAXNODES][MAXNODES];
    
    for (i = 0; i < MAXNODES; ++i)
        for (j = 0; j < MAXNODES; ++j)
            adjprod[i][j] = path[i][j] = adj[i][j];
    for (i = 1; i < MAXNODES; ++i) {
        // i represents the number of times adj has been multiplied by itself to obtain adjprod. At this point path represents all paths of i or less
        prod(adjprod, adj, newprod);
        for (j = 0; j < MAXNODES; ++j)
            for (k = 0; k < MAXNODES; ++k)
                path[j][k] = path[j][k] || newprod[j][k];
        for (j = 0; j < MAXNODES; ++j)
            for (k = 0; k < MAXNODES; ++k)
                adjprod[j][k] = newprod[j][k];
    }
}

int main(int argc, const char * argv[]) {
    int path[MAXNODES][MAXNODES],
        a[MAXNODES][MAXNODES] = {
            { FALSE, FALSE, TRUE, TRUE, FALSE },
            { FALSE, FALSE, TRUE, FALSE, FALSE },
            { FALSE, FALSE, FALSE, TRUE, TRUE },
            { FALSE, FALSE, FALSE, FALSE, TRUE },
            { FALSE, FALSE, FALSE, TRUE, FALSE }
        };
    transclose(a, path);
    
    for (int i = 0; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
    return 0;
}
