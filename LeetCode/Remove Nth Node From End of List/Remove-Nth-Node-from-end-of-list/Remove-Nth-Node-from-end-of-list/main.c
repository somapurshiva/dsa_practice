//
//  main.c
//  Remove-Nth-Node-from-end-of-list
//
//  Created by Shiva Somapur on 12/11/21.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p, *q, *r;
    int count = 0;
    
    p = head;
    q = NULL;
    r = NULL;
    while (p != NULL) {
        p = p->next;
        if (q != NULL)
            q = q->next;
        if (r != NULL)
            r = r->next;
        if (count <= n+1)
            count++;
        if (count == n)
            q = head;
        if (count == n+1)
            r = head;
    }
    if (q == head) {
        head = q->next;
    } else {
        r->next = q->next;
    }
    return head;
}

struct ListNode* getnode(void) {
    return (struct ListNode*) malloc((sizeof(struct ListNode)));
}

void freenode(struct ListNode* p) {
    free(p);
}

struct ListNode* appendNode(struct ListNode* p, int val) {
    struct ListNode* q;
    
    q = getnode();
    q->val = val;
    q->next = p->next;
    p->next = q;
    return q;
}

struct ListNode* generateList(int n) {
    struct ListNode *head = NULL, *p;
    int i;
    
    head = getnode();
    head->val = 1;
    head->next = NULL;
    
    p = head;
    for (i = 1; i < n; i++) {
        p = appendNode(p, i+1);
    }
    return head;
}

void printQ(struct ListNode* head) {
    struct ListNode *p;
    
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    struct ListNode *head;
    
    head = generateList(2);
    head = removeNthFromEnd(head, 1);
    printQ(head);
    return 0;
}
