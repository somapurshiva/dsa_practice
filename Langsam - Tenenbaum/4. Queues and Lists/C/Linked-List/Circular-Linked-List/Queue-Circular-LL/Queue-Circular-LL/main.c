//
//  main.c
//  Queue-Circular-LL
//
//  Created by Shiva Somapur on 17/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define TRUE 1
#define FALSE 0

struct node {
    int info;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR getnode(void) {
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}

void freenode(NODEPTR p) {
    free(p);
}

struct queue {
    NODEPTR rear;
};

int empty(struct queue *pq) {
    return pq->rear == NULL ? TRUE : FALSE;
}

int removeQ(struct queue *pq) {
    NODEPTR p;
    int x;
    if (empty(pq)) {
        printf("Queue is empty\n");
        exit(1);
    }
    p = pq->rear->next;
    pq->rear->next = p->next;
    x = p->info;
    freenode(p);
    return x;
}

void insertQ(struct queue *pq, int x) {
    NODEPTR p;
    
    p = getnode();
    p->info = x;
    
    if (empty(pq))
        pq->rear = p;
    else
        p->next = pq->rear->next;
    pq->rear->next = p;
    pq->rear = p;
}

void printQ(struct queue *pq) {
    NODEPTR p;
    printf("Printing Queue...\n");
    if (empty(pq)) {
        printf("Queue is empty\n");
    }
    // Else fetch the front of the Q
    p = pq->rear->next;
    // Start printing till you get to the rear pointer
    do {
        printf("%d ", p->info);
        if (p != pq->rear)
            printf("-> ");
        p = p->next;
    } while (p != pq->rear->next);
//    while (p != pq->rear->next) {
//
//    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    struct queue q;
    // Initialize
    q.rear = NULL;
//    x = removeQ(&q);
    insertQ(&q, 98);
    insertQ(&q, 28);
    insertQ(&q, 82);
    insertQ(&q, 89);
    insertQ(&q, 124);
    printQ(&q);
    printf("Removed: %d\n", removeQ(&q));
    printf("Removed: %d\n", removeQ(&q));
    printQ(&q);
    printf("Removed: %d\n", removeQ(&q));
    printf("Removed: %d\n", removeQ(&q));
    printQ(&q);
    return 0;
}
