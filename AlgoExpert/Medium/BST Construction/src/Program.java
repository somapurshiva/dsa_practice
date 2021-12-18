import java.util.*;

class Program {
    static class BST {
        public int value;
        public BST left;
        public BST right;

        public BST(int value) {
            this.value = value;
        }

        public BST insert(int value) {
            BST p = this, q = p;
            while (p != null) {
                q = p;
                if (value < p.value)
                    p = p.left;
                else p = p.right;
            }
            if (q.value > value)
                q.left = new BST(value);
            else q.right = new BST(value);
            // Do not edit the return statement of this method.
            return this;
        }

        public boolean contains(int value) {
            BST p = this;
            while (p != null) {
                if (p.value == value)
                    return true;
                if (value < p.value)
                    p = p.left;
                else p = p.right;
            }
            return false;
        }

        public BST remove(int value) {
            if (this.left == null && this.right == null)
                return this;
            BST p = this, q = p;
            while (p != null && p.value != value) {
                q = p;
                if (value < p.value)
                    p = p.left;
                else p = p.right;
            }
            // If p is null at this point, the node isn't present in BST
            if (p != null) {
                // If p has right child, find the in-order successor of p and exchange that with p
                // If p don't have right child, find in-order predecessor of p and exchange that with p

                // In-Order successor flow
                if (p.right != null) {
                    // ins is in-order child and inf is the father of this child node
                    BST ins, inf;
                    ins = p.right;
                    inf = p;
                }

            }
            // Do not edit the return statement of this method.
            return this;
        }
    }
}
