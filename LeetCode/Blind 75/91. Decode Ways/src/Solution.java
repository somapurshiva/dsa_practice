import java.util.HashMap;
import java.util.Map;

class Solution {
    Map<Integer, Integer> memo = new HashMap<>();

    public int numDecodings(String s) {
        return recursiveWithMemo(0, s);
    }

    private int recursiveWithMemo(int index, String s) {
        if (memo.containsKey(index))
            return memo.get(index);

        if (index == s.length())
            return 1;

        if (s.charAt(index) == '0')
            return 0;

        if (index == s.length() - 1)
            return 1;

        int ans = recursiveWithMemo(index + 1, s);
        if (Integer.parseInt(s.substring(index, index + 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, s);
        }

        memo.put(index, ans);
        return ans;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.numDecodings("2125"));
    }
}