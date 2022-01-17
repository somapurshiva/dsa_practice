class Solution {
    public int climbStairs(int n) {
        if (n == 1)
            return 1;
        int[] stepsArr = new int[n+1];
        stepsArr[1] = 1;
        stepsArr[2] = 2;
        for (int i = 3; i < n+1; i++) {
            stepsArr[i] = stepsArr[i-1] + stepsArr[i-2];
        }
        return stepsArr[n];
    }
}