//
//  main.c
//  Shell-Sort
//
//  Created by Shiva Somapur on 14/11/21.
//

#include <stdio.h>

void shellsort(int x[], int n, int incrmnts[], int numinc) {
    int incr, j, k, span, y;
    
    for (incr = 0; incr < numinc; incr++) {
        // Span is the size of increment
        span = incrmnts[incr];
        for (j = span; j < n; j++) {
            // Insert element x[j] into its proper position within its subfile
            y = x[j];
            for (k = j-span; k >= 0 && y < x[k]; k -= span) {
                x[k+span] = x[k];
            }
            x[k+span] = y;
        }
    }
}

int main(int argc, const char * argv[]) {
    int x[8] = { 25, 57, 48, 37, 12, 92, 86, 33 }, incrmnts[3] = { 5, 3, 1 };
    shellsort(x, 8, incrmnts, 3);
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
