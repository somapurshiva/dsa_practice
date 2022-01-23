class Solution {
    public int[] countBits(int n) {
        int[] retArr = new int[n+1];
        for (int i = 1; i <= n; i++)
            retArr[i] = retArr[i/2] + i % 2;
        return retArr;
    }
}