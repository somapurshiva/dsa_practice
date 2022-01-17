import java.util.LinkedList;
import java.util.List;

class Solution {
    int n;
    int k;
    List<List<Integer>> retList = new LinkedList<>();

    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        this.k = k;
        backtrack(1, new LinkedList<>());
        return retList;
    }

    private void backtrack(int initNum, LinkedList<Integer> list) {
        if (list.size() == k) {
            retList.add(new LinkedList<>(list));
            return;
        }
        for (int i = initNum; i <= n; i++) {
            list.add(i);
            backtrack(i + 1, list);
            list.removeLast();
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.combine(4,2));
    }
}