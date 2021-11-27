//
//  main.c
//  Josephus-Problem
//
//  Created by Shiva Somapur on 17/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL 0
#define MAXLEN 50
#define TRUE 1
#define FALSE 0

struct node {
    char info[MAXLEN];
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

int eqstr(char *str1, char *str2) {
    int idx = 0;
    while (str1[idx] != '\0' || str2[idx] != '\0') {
        if (str1[idx] != str2[idx]) {
            return FALSE;
        }
        idx++;
    }
    return TRUE;
}

void insert(NODEPTR *list, char *name) {
    NODEPTR p, q;
    
    p = getnode();
    strcpy(p->info, name);
    if (*list == NULL) {
        *list = p;
        p->next = p;
    } else {
        q = (*list)->next;
        while (q->next != *list)
            q = q->next;
        p->next = *list;
        q->next = p;
    }
}

void delafter(NODEPTR *list, char *name) {
    NODEPTR p = (*list)->next;
    strcpy(name, p->info);
    (*list)->next = p->next;
    (*list) = p->next;
    freenode(p);
}

void printQ(NODEPTR list) {
    NODEPTR p;
    p = list;
    do {
        printf("%s -> ", p->info);
        p = p->next;
    } while (p != list);
    printf("%s\n", p->info);
}

int main(int argc, const char * argv[]) {
    char *end = "end";
    char name[MAXLEN];
    int i, n;
    NODEPTR list = NULL;
    printf("Enter n: ");
    scanf("%d", &n);
    
    printf("Enter names:\n");
    scanf("%s", name);
    while (!eqstr(name, end)) {
        insert(&list, name);
        scanf("%s", name);
    }
    printQ(list);
    printf("The order in which the soldiers are eliminated is:\n");
    while (list != list->next) {
        for (i = 1; i < n-1; i++) {
            list = list->next;
//            printf("List at end of loop: %s\n", list->info);
        }
        delafter(&list, name);
        printf("%s eliminated\n", name);
        printQ(list);
    }
    printf("The soldier who escaped is: %s\n", list->info);
    freenode(list);
    return 0;
}
