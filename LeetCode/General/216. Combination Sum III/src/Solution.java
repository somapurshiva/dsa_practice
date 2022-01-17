import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

class Solution {
    int k;
    int n;
    List<List<Integer>> output = new LinkedList<>();

    public List<List<Integer>> combinationSum3(int k, int n) {
//        this.k = k;
//        this.n = n;
//        backtrack(1, new LinkedList<>());
//        return output;
        LinkedList<Integer> combo = new LinkedList<>();
        List<List<Integer>> results = new LinkedList<>();
        backtrack(n, k, combo, 1, results);
        return results;
    }

    private void backtrack(int initNum, LinkedList<Integer> list) {
        if (list.size() == k && sumOfList(list) == n) {
            output.add(new LinkedList<>(list));
            return;
        }
        for (int currNum = initNum; currNum <= 9 && sumOfList(list) < n; currNum++) {
            list.add(currNum);
            backtrack(currNum + 1, list);
            list.removeLast();
        }
    }

    private int sumOfList(LinkedList<Integer> list) {
      Iterator<Integer> iter = list.iterator();
      int sum = 0;
      while (iter.hasNext()) {
          sum += iter.next();
      }
      return sum;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.combinationSum3(3,9));
    }

    private void backtrack(int remaining, int k, LinkedList<Integer> combo, int initNum, List<List<Integer>> results) {
        if (remaining == 0 && combo.size() == k) {
            results.add(new LinkedList<>(combo));
            return;
        } else if (remaining < 0 || combo.size() == k)
            return;

        for (int currNum = initNum; currNum <= 9; currNum++) {
            combo.add(currNum);
            backtrack(remaining-currNum, k, combo, currNum + 1, results);
            combo.removeLast();
        }
    }
}