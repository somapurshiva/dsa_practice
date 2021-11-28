//
//  main.c
//  Ford-Fulkerson-Algo
//
//  Created by Shiva Somapur on 28/11/21.
//

#include <stdio.h>

#define MAXNODES 6

#define TRUE 1
#define FALSE 0

#define INFINITY 99999

int any(int arr[]) {
    int i;
    for (i = 0; i < MAXNODES; i++) {
        if (arr[i] == TRUE)
            return TRUE;
    }
    return FALSE;
}

// Ford-Fulkerson algorithm to solve the maximum flow problem from source "s" to terminal "t"
// cap[][] is the capacity matrix containing values that show the max capacity between nodes i,i in cap[i][j]
// flow[][] is the output matrix with the solution
// totflow is the maximum flow that can be extablished between s & t
void maxflow (int cap[][MAXNODES], int s, int t, int flow[][MAXNODES], int *ptotflow) {
    int pred, nd, i, x;
    // Once a node has been placed on a partial semipath, it can no longer be used to extend a different semipath. We use the onpath[] array to store flags to indicate whether or not node is on some semipath
    // We also need to indicate which nodes are at the ends of partial semipaths so that such partial semipaths can be extended by adding adjacent nodes. endpath[node] indicates whether or not node is at the end of a partial semipath
    // For each node on a semipath the algo must keep track of what node precedes it on that semipath and the direction of the arc
    // precede[node] points to the node that precedes node on its semipath
    // forward[node] has the value TRUE if and only if the arc is from precede[node] to node
    // improve[node] indicates the amount by which the flow to node may be increased along its semipath
    int precede[MAXNODES], improve[MAXNODES];
    int endpath[MAXNODES], forward[MAXNODES], onpath[MAXNODES];
    // To begin with, set all flow values to zero
    for (nd = 0; nd < MAXNODES; ++nd)
        for (i = 0; i < MAXNODES; ++i)
            flow[nd][i] = 0;
    *ptotflow = 0;
    do {
        // Clear all calculated paths previously and attempt to find a semipath from s to t
        for (nd = 0; nd < MAXNODES; ++nd) {
            endpath[nd] = FALSE;
            onpath[nd] = FALSE;
        }
        // Start the path with s
        endpath[s] = TRUE;
        onpath[s] = TRUE;
        // Assume that s can provide infinite flow
        improve[s] = INFINITY;
        // Attempt to extend an existing path
        while ((onpath[t] == FALSE) && (any(endpath) == TRUE)) {
            // Find the first node that is already part of an existing semipath (endpath[nd] will be true)
            for (nd = 0; endpath[nd] == FALSE; nd++);
            // Once identified, mark that node as not part of semipath
            endpath[nd] = FALSE;
            for (i = 0; i < MAXNODES; ++i) {
                // Search for nodes from nd to i where capacity - flow is avialable and can be utilized first
                if ((flow[nd][i] < cap[nd][i]) && (onpath[i] == FALSE)) {
                    onpath[i] = TRUE;
                    endpath[i] = TRUE;
                    precede[i] = nd;
                    forward[nd] = TRUE;
                    x = cap[nd][i] - flow[nd][i];
                    improve[i] = (improve[nd] < x) ? improve[nd] : x;
                }
                // Also, search for nodes coming in to nd where existing flow can be reduced to improve the overall flow
                if ((flow[i][nd] > 0) && (onpath[i] == FALSE)) {
                    onpath[i] = TRUE;
                    endpath[i] = TRUE;
                    precede[i] = nd;
                    forward[nd] = FALSE;
                    improve[i] = (improve[nd] < flow[i][nd]) ? improve[nd] : flow[i][nd];
                }
            }
        }
        
        // After the above circus, if we were able to find a semipath to t, now update the actual flow values based on updated improve values
        if (onpath[t] == TRUE) {
            // If here, that means that flow on semipath to t can be increased
            x = improve[t];
            *ptotflow += x;
            nd = t;
            while (nd != s) {
                // Travel back along path
                pred = precede[nd];
                // Increase or decrease the flow from pred
                (forward[pred] == TRUE) ? (flow[pred][nd] += x) : (flow[nd][pred] -= x);
                nd = pred;
            }
        }
    } while (onpath[t] == TRUE);
}

int main(int argc, const char * argv[]) {
    int cap[MAXNODES][MAXNODES] = {
        {0,4,6,0,0,0},
        {0,0,0,3,5,0},
        {0,0,0,0,4,0},
        {0,0,0,0,0,5},
        {0,0,0,0,0,4},
        {0,0,0,0,0,0}
    };
    int flow[MAXNODES][MAXNODES], totflow;
    maxflow(cap, 0, 5, flow, &totflow);
    printf("Maxflow: %d\n", totflow);
    printf("Flow Matrix:-- \n");
    for (int i = 0; i < MAXNODES; i++) {
        for (int j = 0; j < MAXNODES; j++)
            printf("%d ", flow[i][j]);
        printf("\n");
    }
    return 0;
}
