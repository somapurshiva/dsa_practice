//
//  main.c
//  Merge-Sort
//
//  Created by Shiva Somapur on 14/11/21.
//

#include <stdio.h>

#define NUMELTS 50

void mergesort1(int x[], int n) {
    int aux[NUMELTS], i, j, k, l1, l2, size, u1, u2;
    // Start with size of 1 to merge files with single element
    size = 1;
    while (size < n) {
        // Initialize lower bound of first file
        l1 = 0;
        // k is the index for aux array
        k = 0;
        // Check to see if there are two files to merge: l1+size < n. if we are at the end and lower bound of first file + size crosses n, we don't effectively have another file to merge with current one
        while (l1+size < n) {
            // Calculate remaining indexes
            l2 = l1+size;
            u1 = l2-1;
            u2 = (l2+size-1 < n) ? l2+size-1 : n-1;
            // Procees to merge two current sub-files
            for(i = l1, j = l2; i <= u1 && j <= u2; k++) {
                // Enter smaller element into the aux array
                if (x[i] <= x[j])
                    aux[k] = x[i++];
                else
                    aux[k] = x[j++];
            }
            // At this point, one of the subfiles has been exhausted. Insert any remaining portions of the other file
            for(; i <= u1; k++)
                aux[k] = x[i++];
            for(; j <= u2; k++)
                aux[k] = x[j++];
            // Advance l1 to the start of the next pair of files
            l1 = u2+1;
        }
        // Copy any remaining single file
        for (i = l1; k < n; i++)
            aux[k++] = x[i];
        // Copy aux into x back and adjust the size (go double)
        for (i = 0; i < n; i++)
            x[i] = aux[i];
        // Go double for size
        size *= 2;
    }
}

int main(int argc, const char * argv[]) {
    int x[9] = { 25, 57, 31, 48, 37, 12, 92, 86, 33 };
    mergesort1(x, 9);
    
    for (int i = 0; i < 9; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
