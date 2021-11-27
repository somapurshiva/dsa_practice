//
//  main.c
//  Dijkstra-Algo
//
//  Created by Shiva Somapur on 26/11/21.
//

#include <stdio.h>

#define MAXNODES 6
#define INFINITY 999
#define MEMBER 1
#define NONMEMBER 0

void shortpath(int weight[][MAXNODES], int s, int t, int *pd, int precede[]) {
    int distance[MAXNODES], perm[MAXNODES];
    int current, i, k = 0, dc;
    int smalldist, newdist;
    // Initialize all values to infinity and non-member
    for (i = 0; i < MAXNODES; ++i) {
        perm[i] = NONMEMBER;
        distance[i] = INFINITY;
    }
    // Start with source: "s" and initialize the values for it in the perm & distance arrays
    perm[s] = MEMBER;
    distance[s] = 0;
    current = s;
    while (current != t) {
        smalldist = INFINITY;
        dc = distance[current];
        // Go through all the nodes and find out the distance of them from the current which started with s, the smallest of them will lead us to the next "current" node
        for (i = 0; i < MAXNODES; i++) {
            // Calculate the distance only if the node isn't evaluated already
            if (perm[i] == NONMEMBER) {
                newdist = dc + weight[current][i];
                // If the calculated new distance is less than than the one already evaluated for node i, set the new distance
                if (newdist < distance[i]) {
                    distance[i] = newdist;
                    precede[i] = current;
                }
                // Choose the smallest distance from the calculated ones and select that as the next "current" node
                if (distance[i] < smalldist) {
                    smalldist = distance[i];
                    k = i;
                }
            }
        }
        // Mark the current pointer to the one which had the smallest distance from the prev evaluation
        current = k;
        perm[current] = MEMBER;
    }
    *pd = distance[t];
}

int main(int argc, const char * argv[]) {
    int weight[][MAXNODES] = {
        { INFINITY, 5, INFINITY, 2, INFINITY, INFINITY },
        { INFINITY, INFINITY, 4, INFINITY, 2, INFINITY },
        { INFINITY, INFINITY, INFINITY, INFINITY, 6, 3 },
        { INFINITY, 8, INFINITY, INFINITY, 7, INFINITY },
        { INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 1 },
        { INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY }
    };
    int dist, precede[MAXNODES];
    for (int i = 0; i < MAXNODES; i++)
        precede[i] = MAXNODES;
    shortpath(weight, 0, 5, &dist, precede);
    printf("Shortest Distance: %d\n", dist);
    printf("Path: ");
    for (int i = 0; i < MAXNODES; i++)
        printf("%d  ", precede[i]);
    printf("\n");
    return 0;
}
