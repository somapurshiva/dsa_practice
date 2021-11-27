//
//  main.c
//  Heap-Sort
//
//  Created by Shiva Somapur on 13/11/21.
//

#include <stdio.h>

int father(int p) {
    return (p - 1)/2;
}

int left(int p) {
    return 2 * p + 1;
}

int right(int p) {
    return 2 * p + 2;;
}

void pqinsert(int dpq[], int k, int elt) {
    int s, f;
    s = k;
    // f points to the father node of s
    f = father(s);
    while (s > 0 && dpq[f] < elt) {
        // If passed element is greater than current father, move the father down to the child node
        dpq[s] = dpq[f];
        // advance the pointer to the father field up the tree
        s = f;
        // Point to the next father now
        f = father(s);
    }
    // In the end we would be pointing to the field where the passed element will be smaller than the father
    dpq[s] = elt;
}

void intrav(int dpq[], int k, int n) {
    if (k < n) {
        intrav(dpq, left(k), n);
        printf("%d ", dpq[k]);
        intrav(dpq, right(k), n);
    }
}

int largeson(int x[], int p, int m) {
    int s;
    // Point s to the left son of p
    s = left(p);
    // If the right son index is less than array length and left son is smaller than right son, return right son
    if (s + 1 <= m && x[s] < x[s+1])
        s = s + 1;
    // If s is out of bounds, return -1
    if ( s > m)
        return (-1);
    else
        return (s);
}

void adjustheap(int dpq[], int root, int k) {
    int f, s;
    f = root;
    s = largeson(dpq, f, k - 1);
    if (s >= 0 && dpq[k] < dpq[s]) {
        dpq[f] = dpq[s];
        adjustheap(dpq, s, k);
    } else
        dpq[f] = dpq[k];
}

void adjustheapnonrecursive(int dpq[], int root, int k) {
    int f, s, kvalue;
    f = root;
    kvalue = dpq[k];
    s = largeson(dpq, f, k - 1);
    while (s >= 0 && kvalue < dpq[s]) {
        dpq[f] = dpq[s];
        f = s;
        s = largeson(dpq, f, k - 1);
    }
    dpq[f] = kvalue;
}

int pqmaxdelete(int dpq[], int k) {
    int p;
    
    p = dpq[0];
    adjustheap(dpq, 0, k - 1);
    return p;
}

void heapsort1(int x[], int n) {
    int i;
    // add elements to the priority queue
    for (i = 0; i < n; i++)
        pqinsert(x, i, x[i]);
    // Select each success element in order
    for (i = n - 1; i > 0; i--)
        x[i] = pqmaxdelete(x, i + 1);
}

void heapsortinline(int x[], int n) {
    int i, elt, s, f, ivalue;
    // Pre-processing: Create initial heap
    for (i = 1; i < n; i++) {
        elt = x[i];
        // pqinsert(x, i, elt)
        s = i;
        f = father(s);
        while (s > 0 && x[f] < elt) {
            x[s] = x[f];
            s = f;
            f = father(s);
        }
        x[s] = elt;
    }
    // Selection phase: repeatedly remove x[0], insert it in its proper position and adjust the heap
    for (i = n-1; i > 0; i--) {
        // pqmaxdelete(x, i+1)
        ivalue = x[i];
        x[i] = x[0];
        
        f = 0;
        // s = largeson(0, i-1)
        if (i == 1)
            s = -1;
        else
            s = 1;
        if (i > 2 && x[2] > x[1])
            s = 2;
        while (s >= 0 && ivalue < x[s]) {
            x[f] = x[s];
            f = s;
            // s = largeson(f, i-1)
            s = left(f);
            if (s + 1 <= i - 1 && x[s] < x[s + 1])
                s = s + 1;
            if (s > i - 1)
                s = -1;
        }
        x[f] = ivalue;
    }
}

int main(int argc, const char * argv[]) {
    int x[8] = { 25, 57, 48, 37, 12, 92, 86, 33 }, n = 8;
//    pqinsert(x, 0, 25);
//    pqinsert(x, 1, 57);
//    pqinsert(x, 2, 48);
//    pqinsert(x, 3, 37);
//    pqinsert(x, 4, 12);
//    pqinsert(x, 5, 92);
//    pqinsert(x, 6, 86);
//    pqinsert(x, 7, 33);
//    for (int i = 0; i < 8; i++) {
//        pqinsert(x, i, x[i]);
//    }
//
//    intrav(x, 0, n);
//
//    x[7] = pqmaxdelete(x, 8);
//
//    printf("\nRemoved %d \n", x[7]);
//
//    intrav(x, 0, n - 1);
//    heapsort1(x, n);
    heapsortinline(x, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
