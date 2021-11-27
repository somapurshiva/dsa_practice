//
//  main.c
//  Simple-Insertion-Sort
//
//  Created by Shiva Somapur on 14/11/21.
//

#include <stdio.h>

void insertsort(int x[], int n) {
    int i, k, y;
    // Assume x[0] is sorted, place remaining elements at right positions from x[1] onwards to sort the whole array
    for (k = 1; k < n; k++) {
        // Insert x[k] into the sorted file
        y = x[k];
        // Move down 1 position all elements greater than y
        for (i = k-1; i>=0 && y<x[i]; i--) {
            x[i+1] = x[i];
        }
        // Insert y at the right position which is i+1 after the above movement
        x[i+1] = y;
    }
}

int main(int argc, const char * argv[]) {
    int x[8] = { 25, 57, 48, 37, 12, 92, 86, 33 };
    insertsort(x, 8);
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
