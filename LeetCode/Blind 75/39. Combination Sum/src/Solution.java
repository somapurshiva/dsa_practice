import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        LinkedList<Integer> combo = new LinkedList<>();
        List<List<Integer>> results = new LinkedList<>();
        backtrack(target, candidates, 0, combo, results);
        return results;
    }

    private void backtrack(int remaining, int[] candidates, int currIdx,LinkedList<Integer> combo, List<List<Integer>> results) {
        if (remaining == 0) {
            results.add(new LinkedList<>(combo));
            return;
        } else if (remaining < 0) return;

        for (int i = currIdx; i < candidates.length; i++) {
            combo.add(candidates[i]);
            backtrack(remaining - candidates[i], candidates, i, combo, results);
            combo.removeLast();
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.combinationSum(new int[] {2,3,5}, 8));
    }
}