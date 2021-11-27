//
//  main.c
//  Warshalls-Algo
//
//  Created by Shiva Somapur on 23/11/21.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAXNODES 5

void transclose (int adj[][MAXNODES], int path[][MAXNODES]) {
    int i, j, k;
    for (i = 0; i < MAXNODES; ++i)
        for (j = 0; j < MAXNODES; ++j)
            path[i][j] = adj[i][j]; // path starts off as adj
    
    for (k = 0; k < MAXNODES; ++k)
        for (i = 0; i < MAXNODES; ++i)
            if (path[i][k] == TRUE)
                for (j = 0; j < MAXNODES; ++j)
                    path[i][j] = path[i][j] || path[k][j];
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
