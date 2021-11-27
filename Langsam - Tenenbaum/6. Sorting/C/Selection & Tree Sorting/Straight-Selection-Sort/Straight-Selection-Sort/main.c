//
//  main.c
//  Straight-Selection-Sort
//
//  Created by Shiva Somapur on 13/11/21.
//

#include <stdio.h>

void selectsort(int x[], int n) {
    int i, indx, j, large;
    
    for (i = n-1; i > 0; i--) {
        // Place the largest number of x[0] through x[i] into large and its index into indx
        large = x[0];
        indx = 0;
        // Starting from index 1 go till current i to find the largest element
        for (j = 1; j <= i; j++) {
            if (x[j] > large) {
                large = x[j];
                indx = j;
            }
        }
        // At the end of the traversal, we will know which is the largest element.. Interchange that with current i
        x[indx] = x[i];
        x[i] = large;
    }
}

int main(int argc, const char * argv[]) {
    int x[8] = { 98, 28, 82, 89, 16, 4, 56, 47 };
    selectsort(x, 8);
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
