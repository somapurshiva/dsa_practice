import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    List<List<Integer>> levels = new ArrayList<>();

    public List<List<Integer>> levelOrder(TreeNode root) {
//        return recursive(root);
        return iterative(root);
    }

    public List<List<Integer>> iterative(TreeNode root) {
        List<List<Integer>> retList = new ArrayList<>();
        if (root == null) return retList;

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int level = 0;

        while (!queue.isEmpty()) {
            retList.add(new ArrayList<>());
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                retList.get(level).add(node.val);
                if (node.left != null)
                    queue.add(node.left);
                if (node.right != null)
                    queue.add(node.right);
            }
            level++;
        }
        return retList;
    }

    private List<List<Integer>> recursive(TreeNode root) {
        if (root == null) return levels;
        helper(root, 0);
        return levels;
    }

    private void helper(TreeNode root, int level) {
        if (levels.size() == level)
            levels.add(new ArrayList<>());

        levels.get(level).add(root.val);
        if (root.left != null)
            helper(root.left, level + 1);
        if (root.right != null)
            helper(root.right, level + 1);
    }
}