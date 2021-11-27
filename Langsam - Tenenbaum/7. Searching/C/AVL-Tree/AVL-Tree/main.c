//
//  main.c
//  AVL-Tree
//
//  Created by Shiva Somapur on 17/11/21.
//

#include <stdio.h>
#include <stdlib.h>

struct nodetype {
    int info;
    int bal;
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

void leftrotation(NODEPTR p) {
    NODEPTR q, hold;
    
    q = p->right;
    hold = q->left;
    q->left = p;
    p->right = hold;
}

void rightrotation(NODEPTR p) {
    NODEPTR q, hold;
    
    q = p->left;
    hold = q->right;
    q->right = p;
    p->left = hold;
}

NODEPTR maketree(int val) {
    NODEPTR p;
    
    p = getnode();
    p->info = val;
    p->bal = 0;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}

NODEPTR avlSearchInsert(NODEPTR tree, int key) {
    NODEPTR p, q, fp, ya, fya, sya;
    int imbal;
    // PART 0 --> If the tree is not initialized, create a new node and point tree pointer to the new node
    if (tree == NULL) {
        tree = maketree(key);
        return tree;
    }
    // PART I: Search and insert into the binary tree
    fp = NULL;
    p = tree;
    fya = NULL;
    ya = p;
    // "ya" points to the youngest ancestor which may become unbalanced. "fya" points to the father of "ya", and "fp" points to the father of "p"
    while (p != NULL) {
        if (key == p->info)
            return p;
        // else key not found, continue the tree traversal
        q = (key < p->info) ? p->left : p->right;
        // Identify the vulnerable ya node by checking the balance value of the nodes
        if (q != NULL)
            if (q->bal != 0) {
                fya = p;
                ya = q;
            }
        fp = p;
        p = q;
    }
    // If we have reached here, the passed key wasn't found. Hence a new node has to be inserted and the tree balanced
    q = maketree(key);
    if (key < fp->info)
        fp->left = q;
    else
        fp->right = q;
    // Now that the node is inserted, the balance on all nodes between "ya" and "q" must be changed from 0
    p = (key < ya->info) ? ya->left : ya->right;
    sya = p;
    // Traverse down till node "q" and update the balances
    while (p != q) {
        if (key < p->info) {
            p->bal = 1;
            p = p->left;
        } else {
            p->bal = -1;
            p = p->right;
        }
    }
    
    // PART II: Ascertain whether or not the tree is unbalanced. If it is, "q" is the newly inserted node. "ya" is its youngest unbalanced ancestor, "fya" is the father of "ya" and "sya" is the son of "ya"in the direction of the imbalance
    // Set a variable ombal with +1 or -1 based on whether new node was inserted to left/right of "ya"
    imbal = (key < ya->info) ? 1 : -1;
    // If the "ya" node was at 0 balance previously, adding a new node won't unbalance it
    if (ya->bal == 0) {
        // another level has been added to the tree but the tree remains balanced
        ya->bal = imbal;
        return q;
    }
    
    if (ya->bal != imbal) {
        // The added node has been placed in the opposite direction of the imbalance. The tree remains balanced.
        ya->bal = 0;
        return q;
    }
    
    // PART III: The additional node has unbalanced the tree. Rebalance it by performing the required rotations and then adjust the balances of the nodes involved
    
    if (sya->bal == imbal) {
        // If both "sya" and "ya" have same imbal value, that means that they have been unbalanced in the same direction. A single rotation is sufficient to balance the tree
        // Point "p" to the "sya" node as it will come on top post rotation and has to be attached back with "fya"
        p = sya;
        if (imbal == 1)
            rightrotation(ya);
        else
            leftrotation(ya);
        ya->bal = 0;
        sya->bal = 0;
    } else {
        // If "sya" and "ya" don't have the same imbal value, that  means they are unbalanced in the opposite directions
        if (imbal == 1) {
            p = sya->right;
            leftrotation(sya);
            ya->left = p;
            rightrotation(ya);
        } else {
            p = sya->left;
            ya->right = p;
            rightrotation(sya);
            leftrotation(ya);
        }
        // Adjust the bal value for the involved nodes
        if (p->bal == 0) {
            // "p" was the inserted node
            ya->bal = 0;
            sya->bal = 0;
        } else {
            if (p->bal == imbal) {
                ya->bal = -imbal;
                sya->bal = 0;
            } else {
                ya->bal = 0;
                sya->bal = imbal;
            }
        }
        p->bal = 0;
    }
    
    // Adjust the "fya" pointer to the rotated subtree
    if (fya == NULL)
        tree = p;
    else
        if (ya == fya->right)
            fya->right = p;
        else
            fya->left = p;
    return q;
}

void intrav(NODEPTR p) {
    if (p != NULL) {
        intrav(p->left);
        printf("%d ", p->info);
        intrav(p->right);
    }
}

int main(int argc, const char * argv[]) {
    int arr[13] = { 14, 17, 11, 7, 53, 4, 13, 12, 8, 60, 19, 16, 20 };
    NODEPTR tree;
    printf("Inserting %d ...\n", arr[0]);
    tree = avlSearchInsert(NULL, arr[0]);
    intrav(tree);
    printf("\n");
    for (int i = 1; i < 13; i++) {
        printf("Inserting %d ...\n", arr[i]);
        avlSearchInsert(tree, arr[i]);
        intrav(tree);
        printf("\n");
    }
    return 0;
}
