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
            // Write your code here.
            BST parentNode = null;
            BST currNode = this;
            while (currNode != null) {
                parentNode = currNode;
                if (value < currNode.value)
                    currNode = currNode.left;
                else currNode = currNode.right;
            }
            if (value < parentNode.value)
                parentNode.left = new BST(value);
            else parentNode.right = new BST(value);
            // Do not edit the return statement of this method.
            return this;
        }

        public boolean contains(int value) {
            // Write your code here.
            BST currNode = this;
            while (currNode != null) {
                if (value < currNode.value)
                    currNode = currNode.left;
                else if (value > currNode.value)
                    currNode = currNode.right;
                else return true;
            }
            return false;
        }

        public BST remove(int value) {
            remove(value, null);
            return this;
        }

        public BST remove(int value, BST parentNode) {
            // Write your code here.
            BST currNode = this;
            while (currNode != null) {
                if (value < currNode.value) {
                    parentNode = currNode;
                    currNode = currNode.left;
                } else if (value > currNode.value) {
                    parentNode = currNode;
                    currNode = currNode.right;
                } else {
                    // At this point we have found the value to be removed.
                    // Difficult case - both children are present
                    if (currNode.left != null && currNode.right != null) {
                        // Find the leftmost node on the right subtree
                        BST rplNode = currNode.right;
                        while (rplNode.left != null)
                            rplNode = rplNode.left;
                        currNode.value = rplNode.value;
                        currNode.right.remove(currNode.value, currNode);
                    } else if (parentNode == null) {
                        if (currNode.left != null) {
                            currNode.value = currNode.left.value;
                            currNode.right = currNode.left.right;
                            currNode.left = currNode.left.left;
                        } else if (currNode.right != null) {
                            currNode.value = currNode.right.value;
                            currNode.left = currNode.right.left;
                            currNode.right = currNode.right.right;
                        } else {
                            break;
                        }
                    } else if (parentNode.left == currNode) {
                        parentNode.left = currNode.left != null ? currNode.left : currNode.right;
                    } else if (parentNode.right == currNode) {
                        parentNode.right = currNode.left != null ? currNode.left : currNode.right;
                    }
                    break;
                }
            }
            // Do not edit the return statement of this method.
            return this;
        }
    }
}
