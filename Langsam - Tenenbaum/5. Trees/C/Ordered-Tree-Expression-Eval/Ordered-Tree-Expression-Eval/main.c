//
//  main.c
//  Ordered-Tree-Expression-Eval
//
//  Created by Shiva Somapur on 09/11/21.
//

#include "treenode.h"

void replace(NODEPTR p) {
    float value;
    NODEPTR q, r;
    if (p->utype == OPERATOR) {
        // The tree will always have an operator at its root
        q = p->son;
        while (q != NULL) {
            // Replace all the subtrees by operands
            replace(q);
            q = q->next;
        }
        // Apply operator in root on the operands
        value = apply(p);
        // Replace the operator by the result
        p->utype = OPERAND;
        p->info.val = value;
        // Free all the subtrees
        q = p->son;
        p->son = NULL;
        while (q != NULL) {
            r = q;
            q = q->next;
            freenode(r);
        }
    }
}

float evaltree(NODEPTR p) {
    NODEPTR q;
    float result;
    
    replace(p);
    result = p->info.val;
    freenode(p);
    return result;
}

void buildtree(NODEPTR root) {
    NODEPTR _firstAsterisk, _plusOperator, _secondAsterisk;
    
    addsonOprtr(root, '*');
    addsonOprtr(root, '+');
    
    _firstAsterisk = root->son;
    _plusOperator = root->son->next;
    
    addsonOprtr(_plusOperator, '*');
    
    _secondAsterisk = _plusOperator->son;
    
    addsonVal(_firstAsterisk, 1);
    addsonVal(_firstAsterisk, 2);
    
    addsonVal(_plusOperator, 5);
    
    addsonVal(_secondAsterisk, 3);
    addsonVal(_secondAsterisk, 4);
}

int main(int argc, const char * argv[]) {
    NODEPTR root;
    float result;
    
    root = getnode();
    root->utype = OPERATOR;
    root->info.oprtr = '+';
    buildtree(root);
    
    result = evaltree(root);
    
    printf("Result of the expression tree: %f", result);
    
    return 0;
}
