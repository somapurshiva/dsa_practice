//
//  main.c
//  Minimax-Game-Tree
//
//  Created by Shiva Somapur on 10/11/21.
//

#include "nodetype.h"

void printBoard(char brd[][3]) {
    printf("%c %c %c\n", brd[0][0], brd[0][1], brd[0][2]);
    printf("%c %c %c\n", brd[1][0], brd[1][1], brd[1][2]);
    printf("%c %c %c\n", brd[2][0], brd[2][1], brd[2][2]);
}

void printBoards(NODEPTR p) {
    while (p != NULL) {
        printf("Printing....\n");
        printBoard(p->board);
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {
    char brd[3][3] = {{BLANK, BLANK, BLANK}, {BLANK, BLANK, BLANK}, {BLANK, BLANK, BLANK}};
    char newbrd[3][3];
    nextmove(brd, 2, X, newbrd);
    printBoard(newbrd);
    return 0;
}
