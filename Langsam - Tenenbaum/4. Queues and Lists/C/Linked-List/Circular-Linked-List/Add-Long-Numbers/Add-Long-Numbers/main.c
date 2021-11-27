//
//  main.c
//  Add-Long-Numbers
//
//  Created by Shiva Somapur on 17/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

#define MAXLEN 100

int hunthou = 1000L;

NODEPTR convertToNodes(long longNumber) {
    NODEPTR head = getnode(), p;
    int carry, rem;
    head->info = -1;
    head->next = head;
    p = head;
    do {
        carry = (int) longNumber / hunthou;
        rem = (int) longNumber % hunthou;
        insafter(p, rem);
        p = p->next;
        longNumber = carry;
    } while (carry != 0);
    return head;
}

void printNum(NODEPTR p) {
    while (p->next->info != -1) {
        p = p->next;
        printf("%d ", p->info);
    }
    printf("\n");
}

NODEPTR addint(NODEPTR p, NODEPTR q) {
    NODEPTR s = getnode();
    long int carry, number, total;
    p = p->next;
    q = q->next;
    s->info = -1;
    s->next = s;
    carry = 0;
    while (p->info != -1 && q->info != -1) {
        total = p->info + q->info + carry;
        number = total % hunthou;
        insafter(s, number);
        carry = total / hunthou;
        s = s->next;
        p = p->next;
        q = q->next;
    }
    // Here there mau be more nodes left in one of the two lists
    while (p->info != -1) {
        total = p->info + carry;
        number = total / hunthou;
        insafter(s, number);
        carry = total / hunthou;
        s = s->next;
        p = p->next;
    }
    while (q->info != -1) {
        total = q->info + carry;
        number = total % hunthou;
        insafter(s, number);
        carry = total / hunthou;
        s = s->next;
        q = q->next;
    }
    if (carry == 1) {
        insafter(s, carry);
        s = s->next;
    }
    return s->next;
}

int main(int argc, const char * argv[]) {
    NODEPTR p1, p2;
    long n1, n2;
    printf("Enter number 1: ");
    scanf("%ld", &n1);
    printf("Enter number 2: ");
    scanf("%ld", &n2);
    p1 = convertToNodes(n1);
    p2 = convertToNodes(n2);
    printNum(p1);
    printNum(p2);
    printf("Sum of Numbers: ");
    printNum(addint(p1, p2));
    return 0;
}
