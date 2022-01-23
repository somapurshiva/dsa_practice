public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int bits = 32;
        int retVal = 0;
        int mask = 1;
        while (bits >= 0) {
            if ((n & mask) != 0) {
                retVal = retVal | (1 << bits);
            }
            mask = mask << 1;
            bits--;
        }
        return retVal;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.reverseBits(Integer.MAX_VALUE));
    }
}