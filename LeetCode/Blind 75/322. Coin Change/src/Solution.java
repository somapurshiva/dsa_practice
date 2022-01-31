import java.util.Arrays;

class Solution {
    private Integer[] memo;

    public int coinChange(int[] coins, int amount) {
//        return bruteForceRecursion(coins, amount);
        return dp(coins, amount);
    }

    private int bruteForceRecursion(int[] coins, int amount) {
//        return recursionHelper(coins, amount);
        memo = new Integer[amount + 1];
        return recursionWithMemoization(coins, amount);
    }

    private int recursionHelper(int[] coins, int remain) {
        if (remain < 0)
            return -1;
        if (remain == 0)
            return 0;
        int minCount = Integer.MAX_VALUE;
        for (int coin: coins) {
            int count = recursionHelper(coins, remain - coin);
            if (count == -1)
                continue;
            minCount = Math.min(minCount, count + 1);
        }
        return minCount == Integer.MAX_VALUE ? -1 : minCount;
    }

    private int recursionWithMemoization(int[] coins, int remain) {
        if (remain < 0)
            return -1;
        if (remain == 0)
            return 0;
        if (memo[remain] != null)
            return memo[remain];

        int minCount = Integer.MAX_VALUE;
        for (int coin : coins) {
            int count = recursionWithMemoization(coins, remain - coin);
            if (count == -1)
                continue;
            minCount = Math.min(minCount, count + 1);
        }
        memo[remain] = minCount == Integer.MAX_VALUE ? -1 : minCount;
        return memo[remain];
    }

    private int dp(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        // Fill the dp array with value: amt + 1 instead of Integer.MAX_VALUE to avoid overflow issues
        Arrays.fill(dp, amount + 1);
        // Value of 0 can be achieved by zero coins itself
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin < 0) continue;
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }

    public static void main (String[] args) {
        Solution s = new Solution();
        System.out.println(s.coinChange(new int[] {1,2,5}, 11));
        System.out.println(s.coinChange(new int[] {2}, 3));
        System.out.println(s.coinChange(new int[] {1}, 0));
    }
}
