//
//  main.c
//  Add-Diff-Numbers
//
//  Created by Shiva Somapur on 17/10/21.
//

#include <stdio.h>
#include <math.h>
#include "node.h"

#define TRUE 1
#define FALSE 0

long int hunthou = 100L;

int compabs(NODEPTR p, NODEPTR q) {
    NODEPTR r, s;
    if (abs(p->info) > abs(q->info))
        return 1;
    if (abs(p->info) < abs(q->info))
        return -1;
    // Counts are equal
    r = p->left;
    s = q->left;
    while (r != p) {
        if (r->info > s->info)
            return 1;
        if (r->info < s->info)
            return -1;
        r = r->left;
        s = s->left;
    }
    return 0;
}

NODEPTR addiff(NODEPTR p, NODEPTR q) {
    int count;
    NODEPTR pptr, qptr, r, s, zeroptr;
    long int borrow, diff;
    int zeroflag;
    // Initialize variables
    count = 0;
    borrow = 0;
    zeroflag = FALSE;
    // Generate header node for sum
    r = getnode();
    r->left = r;
    r->right = r;
    // Traverse the two lists
    pptr = p->right;
    qptr = q->right;
    while (qptr != q) {
        diff = pptr->info - borrow - qptr->info;
        if (diff >= 0)
            borrow = 0;
        else {
            diff = diff + hunthou;
            borrow = 1;
        }
        // Generate a new node and insert it to the left of the header in sum
        insertleft(r, diff);
        count++;
        // Test for zero node
        if (diff == 0) {
            if (zeroflag == FALSE)
                zeroptr = r->left;
            zeroflag = TRUE;
        } else
            zeroflag = FALSE;
        pptr = pptr->right;
        qptr = qptr->right;
    }
    while (pptr != p) {
        diff = pptr->info - borrow;
        if (diff >= 0)
            borrow = 0;
        else {
            diff = diff + hunthou;
            borrow = 1;
        }
        insertleft(r, diff);
        count++;
        if (diff == 0) {
            if (zeroflag == FALSE)
                zeroptr = r->left;
            zeroflag = TRUE;
        } else
            zeroflag = FALSE;
        pptr = pptr->right;
    }
    if (zeroflag == TRUE)
        while (zeroptr != r) {
            s = zeroptr;
            zeroptr = zeroptr->right;
            delete(s, &diff);
            count--;
        }
    if (p->info > 0)
        r->info = count;
    else
        r->info = -count;
    return r;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
