//
//  main.c
//  Josephus-using-Tree
//
//  Created by Shiva Somapur on 07/11/21.
//

#include "nodetype.h"

int follower(int size, int m, int *pk) {
    int j;
    j = *pk - 2 + m;
    *pk = (j % size) + 1;
    return findelement(*pk);
}

int main(int argc, const char * argv[]) {
    int k, m, n, p, size;
    
    printf("Enter total members (n): ");
    scanf("%d", &n);
    printf("Enter the index to be removed (m): ");
    scanf("%d", &m);
    
    // Build the tree n by taking inputs from the user
    buildtree(n);
    
    // First element to be removed will be n+1 as we need to start counting from index 1
    k = n + 1;
    
    for (size = n; size > 2; --size) {
        // Find the next element to be removed based on current k
        // remove that element and repeat till only one element is left
        p = follower(size, m, &k);
        printf("Element removed: %s\n", node[p].info);
        delete(p);
    }
    printf("Last element remaining: %s", node[0].info);
    return 0;
}
