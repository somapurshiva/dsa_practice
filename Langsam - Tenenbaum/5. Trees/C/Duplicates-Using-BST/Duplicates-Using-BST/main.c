//
//  main.c
//  Duplicates-Using-BST
//
//  Created by Shiva Somapur on 20/10/21.
//

#include "nodetype.h"

int main(int argc, const char * argv[]) {
    NODEPTR ptree, p, q;
    int number, i = 1;
    int arr[] = { 14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5 };
    ptree = maketree(arr[0]);
    while (i < 15) {
        number = arr[i];
        p = q = ptree;
        while (p->info != number && q != NULL) {
            p = q;
            if (number < p->info) {
                q = p->left;
            } else {
                q = p->right;
            }
        }
        if (number == p->info) {
            printf("%d is duplicate\n", number);
        } else if (number < p->info) {
            setleft(p, number);
        } else {
            setright(p, number);
        }
        i++;
    }
    preOrder(ptree);
    return 0;
}
