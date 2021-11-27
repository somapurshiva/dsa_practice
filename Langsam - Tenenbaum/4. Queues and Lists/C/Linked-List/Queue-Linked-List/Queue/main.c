//
//  main.c
//  Linked-List
//
//  Created by Shiva Somapur on 12/10/21.
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
    NODEPTR front, rear;
};

int empty(struct queue *pq) {
    return pq->front == NULL ? TRUE : FALSE;
}

void insert(struct queue *pq, int x) {
    NODEPTR p;
    
    p = getnode();
    p->info = x;
    p->next = NULL;
    if (pq->rear == NULL)
        pq->front = p;
    else
        (pq->rear)->next = p;
    pq->rear = p;
}

int removeFrmQ(struct queue *pq) {
    NODEPTR p;
    int x;
    if (empty(pq)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    p = pq->front;
    x = p->info;
    pq->front = p->next;
    if (pq->front == NULL) {
        pq->rear = NULL;
    }
    freenode(p);
    return x;
}

void insafter(NODEPTR p, int x) {
    NODEPTR q;
    if (p == NULL) {
        printf("Void insertion\n");
        exit(1);
    }
    q = getnode();
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void delafter(NODEPTR p, int *px) {
    NODEPTR q;
    if ((p == NULL) || (p->next == NULL)) {
        printf("Void deletion\n");
        exit(1);
    }
    q = p->next;
    *px = q->info;
    p->next = q->next;
    freenode(q);
}

void printQ(struct queue *pq) {
    NODEPTR p = pq->front;
    while (p != NULL) {
        printf("%d", p->info);
        if (p->next != NULL) {
            printf("->");
        }
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    struct queue q;
    // Initialize the queue
    q.front = q.rear = NULL;
    insert(&q, 20);
    insert(&q, 30);
    insert(&q, 40);
    insert(&q, 50);
    insert(&q, 60);
    printQ(&q);
    return 0;
}
