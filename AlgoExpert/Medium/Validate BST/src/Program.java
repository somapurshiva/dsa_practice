import java.util.*;

class Program {
    public static boolean validateBst(BST tree) {
        return validateValues(tree, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    public static boolean validateValues(BST tree, int minVal, int maxVal) {
        if (tree == null)
            return true;
        if (tree.value >= minVal && tree.value < maxVal) {
            return validateValues(tree.left, minVal, tree.value) && validateValues(tree.right, tree.value, maxVal);
        } else return false;
    }

    static class BST {
        public int value;
        public BST left;
        public BST right;

        public BST(int value) {
            this.value = value;
        }
    }
}
