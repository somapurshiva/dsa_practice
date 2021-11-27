//
//  main.c
//  Radix-Sort
//
//  Created by Shiva Somapur on 14/11/21.
//

#include <stdio.h>
#include <math.h>

#define NUMELTS 10

void radixsort1(int x[], int n, int klimit) {
    int front[10], rear[10];
    struct {
        int info;
        int next;
    } node[NUMELTS];
    int exp, first, i, j, k, p, q, y;
    // Initialize Linked List
    for (i = 0; i < n-1; i++) {
        node[i].info = x[i];
        node[i].next = i+1;
    }
    node[n-1].info = x[n-1];
    node[n-1].next = -1;
    // first is the head of the linked list
    first = 0;
    // Number of significant bits passed from caller in klimit
    for (k = i; k < klimit; k++) {
        for (i = 0; i < 10; i++) {
            // Initialize the queues
            rear[i] = -1;
            front[i] = -1;
        }
        // Process each element in the linked list
        while (first != -1) {
            p = first;
            first = node[first].next;
            // Get current node's value in a local variable
            y = node[p].info;
            // Extract the kth digit
            // Raise 10 to (k-1)th power
            exp = pow(10, k-1);
            // j holds the kth digit of the number
            j = (y/exp)%10;
            // Insert y into queue[j]
            q = rear[j];
            // If the rear queue is empty, put current node in front queue
            if (q == -1)
                front[j] = p;
            else
                node[q].next = p;
            rear[j] = p;
        }
        // At this point each record is in its proper queue based on digit k. We now form a single list from all the queue elements.
        // Find the first element
        for (j = 0; j < 10 && front[j] == -1; j++);
        first = front[j];
        // Once the first element is found, Link up remaining queues
        while (j <= 9) {
            // Find the next element
            for (i = j+1; i < 10 && front[i] == -1; i++);
            if (i <= 9) {
                p = i;
                node[rear[j]].next = front[i];
            }
            j = i;
        }
        node[rear[p]].next = -1;
    }
    // Copy bacj to original array
    for (i = 0; i < n; i++) {
        x[i] = node[first].info;
        first = node[first].next;
    }
}

void countSort(int input[], int n, int output[], int pos) {
    int count[n];
    // First set up count array with count values based on the value of the digit in (pos) position
    for (int i = 0; i < n; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[(input[i]/pos)%10]++;
    // Update the count array to reflect the positions by summing adjacent values
    for (int i = 1; i < n; i++)
        count[i] += count[i-1];
    // Finally traverse the input array in reverse to fill the output array
    for (int i = n-1; i >= 0; i--)
        output[--count[(input[i]/pos)%10]] = input[i];
}

int* radixcountsort(int x[], int n, int k) {
    int y[n], pos, i;
    for (i = 0, pos = 1; i < k; i++, pos *= 10) {
        // For even pass, use x array as input and y array as output
        if (i % 2 ==  0)
            countSort(x, n, y, pos);
        else
            countSort(y, n, x, pos);
    }
    if (i % 2 == 0)
        return x;
    else
        return y;
}

int main(int argc, const char * argv[]) {
    int x[10] = { 432, 8, 530, 90, 88, 1231, 11, 45, 677, 199 }, *y;
//    radixsort1(x, 9, 2);
    
    y = radixcountsort(x, 10, 4);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");
    return 0;
}
