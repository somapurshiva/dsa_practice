class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode() {}
     TreeNode(int val) { this.val = val; }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
         this.left = left;
         this.right = right;
     }
}
class Solution {
    private Integer prev;

    public boolean isValidBST(TreeNode root) {
//        return validate(root, null, null);
        prev = null;
        return inorder(root);
    }

    private boolean validate(TreeNode node, Integer minVal, Integer maxVal) {
        if (node == null) return true;
        if ((minVal != null && node.val <= minVal) || (maxVal != null && node.val >= maxVal)) return false;
        return validate(node.left, minVal, node.val) && validate(node.right, node.val, maxVal);
    }

    private boolean inorder(TreeNode node) {
        if (node == null) return true;
        if (!inorder(node.left)) return false;
        if (prev != null && node.val <= prev) return false;
        prev = node.val;
        return inorder(node.right);
    }
}