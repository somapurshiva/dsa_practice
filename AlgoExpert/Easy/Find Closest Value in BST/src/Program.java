import java.util.*;

class Program {
    public static int findClosestValueInBst(BST tree, int target) {
        int closest = Integer.MAX_VALUE;
        while (tree != null) {
            if (target == tree.value)
                return tree.value;
            if (Math.abs(Math.abs(target) - Math.abs(tree.value)) < Math.abs(Math.abs(target) - Math.abs(closest)))
                closest = tree.value;
            if (target < tree.value)
                tree = tree.left;
            else tree = tree.right;
        }
        return closest;
    }

    static class BST {
        public int value;
        public BST left;
        public BST right;

        public BST(int value) {
            this.value = value;
        }
    }

    public static void main(String[] args) {
        BST v1 = new BST(1);
        BST v5_1 = new BST(5);
        BST v14 = new BST(14);
        BST v22 = new BST(22);
        BST v2 = new BST(2);
        v2.left = v1;
        BST v5 = new BST(5);
        v5.left = v2;
        v5.right = v5_1;
        BST v10 = new BST(10);
        v10.left = v5;
        BST v15 = new BST(15);
        v10.right = v15;
        BST v13 = new BST(13);
        v13.right = v14;
        v15.left = v13;
        v15.right = v22;

        System.out.println(findClosestValueInBst(v10, 12));
    }
}
