//
//  nodetype.h
//  List-as-Binary-Tree
//
//  Created by Shiva Somapur on 07/11/21.
//

#ifndef nodetype_h
#define nodetype_h

#include<stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAXELTS 100 // Maximum number of list elements
#define NUMNODES 2 * MAXELTS - 1
#define BLANKS "                   " // 20 blanks

struct nodetype {
    char info[20];
    int lcount;
    int used;
} node[NUMNODES];

int father(int p) {
    return (p - 1)/2;
}

int left(int p) {
    return 2 * p + 1;
}

int right(int p) {
    return 2 * p + 2;
}

int isLeft(int p) {
    return p % 2 != 0;
}

int setLeftLcount(int p, int lcount) {
    int l = left(p);
    node[l].used = TRUE;
    node[l].lcount = lcount;
    strcpy(node[l].info, BLANKS);
    return l;
}

int setLeftInfo(int p, char info[]) {
    int l = left(p);
    node[l].used = TRUE;
    strcpy(node[l].info, info);
    return l;
}

int setRightLcount(int p, int lcount) {
    int r = right(p);
    node[r].used = TRUE;
    node[r].lcount = lcount;
    strcpy(node[r].info, BLANKS);
    return r;
}

int setRightInfo(int p, char info[]) {
    int r = right(p);
    node[r].used = TRUE;
    strcpy(node[r].info, info);
    return r;
}

#endif /* nodetype_h */
