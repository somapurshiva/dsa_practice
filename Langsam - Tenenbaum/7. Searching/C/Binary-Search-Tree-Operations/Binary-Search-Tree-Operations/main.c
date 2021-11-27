//
//  main.c
//  Binary-Search-Tree-Operations
//
//  Created by Shiva Somapur on 15/11/21.
//

#include <stdio.h>
#include <stdlib.h>

#define NILL 0

struct nodetype {
    int info;
    struct nodetype *left;
    struct nodetype *right;
};

typedef struct nodetype *NODEPTR;

NODEPTR getnode(void) {
    return (NODEPTR) malloc(sizeof(struct nodetype));
}

void freenode(NODEPTR p) {
    free(p);
}

NODEPTR maketree(int val) {
    NODEPTR p;
    
    p = getnode();
    p->info = val;
    p->left = NILL;
    p->right = NILL;
    
    return p;
}

NODEPTR setleft(NODEPTR p, int val) {
    NODEPTR q;
    
    if (p->left != NILL) {
        printf("Invalid operation. Left child already present.\n");
        exit(1);
    }
    
    q = maketree(val);
    p->left = q;
    
    return q;
}

NODEPTR setright(NODEPTR p, int val) {
    NODEPTR q;
    
    if (p->right != NILL) {
        printf("Invalid operation. Right child already present.\n");
        exit(1);
    }
    
    q = maketree(val);
    p->right = q;
    
    return q;
}

NODEPTR formNode(int arr[], int low, int high) {
    int mid = (low+high)/2;
    NODEPTR midPtr = maketree(arr[mid]);
    
    if (low < high) {
        if (mid != low)
            midPtr->left = formNode(arr, low, mid-1);
        if (mid != high)
            midPtr->right = formNode(arr, mid+1, high);
    }
    return midPtr;
}

void intrav(NODEPTR p) {
    if (p != NILL) {
        intrav(p->left);
        printf("%d ",p->info);
        intrav(p->right);
    }
}

NODEPTR searchOrInsert(NODEPTR tree, int key) {
    NODEPTR p, q, v;
    
    q = NILL;
    p = tree;
    while (p != NILL) {
        if (key == p->info)
            return p;
        q = p;
        if (key < p->info)
            p = p->left;
        else
            p = p->right;
    }
    v = maketree(key);
    if (q == NILL)
        tree = v;
    else
        if (key < q->info)
            q->left = v;
        else
            q->right = v;
    return v;
}

void deleteKey(NODEPTR tree, int key) {
    NODEPTR p, q, rp, f, s; // rp is the pointer that will replace p, f is father of rp, s is son of rp
    p = tree;
    q = NILL;
    // Search for the node with the passed key value as info, set p to point to the node and q to its father, if any
    while (p != NILL && p->info != key) {
        q = p;
        p = (key < p->info) ? p->left : p->right;
    }
    if (p == NILL) {
        printf("Key: %d not found in tree...\n", key);
        return;
    }
    // Set the variable rp to the node that will replace node(p)
    // First two cases: the node to be deleted has at most one son
    if (p->left == NILL)
        rp = p->right;
    else
        if (p->right == NILL)
            rp = p->left;
        else {
            // Third case: node(p) has two sons. Set rp to the inorder successor of p and f to the father of rp. Later rp's right node will replace rp and associate itself with f
            f = p;
            rp = p->right;
            // s is always the left son of rp. As we will traverse to find an rp that has left son null
            s = rp->left;
            while (s != NILL) {
                f = rp;
                rp = s;
                s = rp->left;
            }
            // At this point, rp is the inorder successor of p
            // More processing if rp is not the very next child of p
            if (f != p) {
                // p is not the father of rp
                // Move rp's right child and assign it to left node of f, effectively deleting rp from the tree
                f->left = rp->right;
                // Now move p's right node hierarchy under rp
                rp->right = p->right;
            }
            // set the left node hierarchy of p under rp now
            rp->left = p->left;
        }
    // Insert rp into the position formerly occupied by p now
    if (q == NILL)
        tree = rp;
    else
        if (p == q->left)
            q->left = rp;
        else
            q->right = rp;
    printf("Replaced node: %d with %d post deletion...\n", p->info, (rp == NILL) ? -1 : rp->info);
    freenode(p);
}

int main(int argc, const char * argv[]) {
    NODEPTR tree, tree2, p;
    int arr[19] = { 30, 47, 86, 95, 115, 130, 138, 159, 166, 184, 206, 212, 219, 224, 237, 258, 296, 307, 314 };
    int arr2[13] = { 1, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    tree = formNode(arr, 0, 18);
    intrav(tree);
    printf("\n");
    printf("Searching for 296...\n");
    p = searchOrInsert(tree, 296);
    printf("296's left child: %d\n", p->left->info);
    printf("296's right child: %d\n", p->right->info);
    
    printf("Inserting 80 as on search it won't be found...\n");
    p = searchOrInsert(tree, 80);
    printf("Tree after adding 80: \n");
    intrav(tree);
    printf("\n");
    deleteKey(tree, 9828);
    
    
    tree2 = formNode(arr2, 0, 12);
    intrav(tree2);
    printf("\n");
    deleteKey(tree2, 11);
    intrav(tree2);
    printf("\n");
    deleteKey(tree2, 8);
    intrav(tree2);
    printf("\n");
    return 0;
}
