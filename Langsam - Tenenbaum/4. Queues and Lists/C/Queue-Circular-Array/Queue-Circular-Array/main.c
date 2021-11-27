//
//  main.c
//  Queue-Circular-Array
//
//  Created by Shiva Somapur on 10/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0

struct queue {
    int items[MAXQUEUE];
    int front, rear;
};

int empty(struct queue *pq) {
    return ((pq->front == pq->rear) ? TRUE : FALSE);
}

int remvq(struct queue *pq) {
    if (empty(pq)) {
        printf("Queue Underflow!");
        exit(1);
    }
    if (pq->front == MAXQUEUE - 1)
        pq->front = 0;
    else
        (pq->front)++;
    return (pq->items[pq->front]);
}

void remvandtest(struct queue *pq, int *px, int *pund) {
    if (empty(pq)) {
        *pund = TRUE;
        return;
    }
    *pund = FALSE;
    if (pq->front == MAXQUEUE - 1)
        pq->front = 0;
    else
        (pq->front)++;
    *px = (pq->items[pq->front]);
}

void insert(struct queue *pq, int x) {
    // Make room for new element
    if (pq->rear == MAXQUEUE - 1)
        pq->rear = 0;
    else
        (pq->rear)++;
    if (pq->rear == pq->front) {
        printf("Queue Overflow!");
        exit(1);
    }
    pq->items[pq->rear] = x;
    return;
}

int main(int argc, const char * argv[]) {
    struct queue q;
    int x;
    q.front = q.rear = MAXQUEUE - 1;
    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    insert(&q, 4);
    x = remvq(&q);
    insert(&q, 5);
//    insert(&q, 6);
    x = remvq(&q);
    insert(&q, 7);
    insert(&q, 8);
    return 0;
}
