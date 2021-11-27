//
//  main.c
//  Bubble-Sort
//
//  Created by Shiva Somapur on 11/11/21.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

void bubble(int x[], int n) {
    int switched = TRUE;
    int pass, j, temp;
    for (pass = 0; pass < n-1 && switched == TRUE; pass++) {
        // Set switched to false so that it can be set to true when elements are actually exchanged
        switched = FALSE;
        // inner loop starts from 0 till one element behind pass
        for (j = 0; j < n-1-pass; j++) {
            if (x[j] > x[j+1]) {
                switched = TRUE;
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int i;
    int arr[] = {25, 57, 48, 37, 12, 92, 86, 33};
    bubble(arr, 8);
    for (i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
