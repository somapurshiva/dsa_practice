import java.util.HashMap;
import java.util.Map;

class Solution {
    Map<Integer, Integer> memo = new HashMap<>();

    public int numDecodings(String s) {
//        return recursiveWithMemo(0, s);
//        return dpIterativeWithSpace(s);
        return dpIterativeConstSpace(s);
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

    private int dpIterativeWithSpace(String s) {
        if (s.charAt(0) == '0')
            return 0;

        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != '0')
                dp[i + 1] = dp[i];

            int twoDigit = Integer.parseInt(s.substring(i-1, i+1));
            if (twoDigit >= 10 && twoDigit <= 26)
                dp[i + 1] += dp[i-1];
        }
        return dp[s.length()];
    }

    private int dpIterativeConstSpace(String s) {
        if (s.charAt(0) == '0')
            return 0;
        int twoBack = 1;
        int oneBack = 1;

        for (int i = 1; i < s.length(); i++) {
            int current = 0;
            if (s.charAt(i) != '0')
                current += oneBack;

            int twoDigit = Integer.parseInt(s.substring(i-1, i+1));
            if (twoDigit >= 10 && twoDigit <= 26)
                current += twoBack;

            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.numDecodings("2125"));
    }
}
