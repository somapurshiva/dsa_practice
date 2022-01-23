public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        int mask = 1;
        int bits = 32;
        while (bits >= 0) {
            if ((n & mask) != 0)
                count++;
            mask = mask << 1;
            bits--;
        }
        return count;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
//        System.out.println(s.hammingWeight(-1));
        System.out.println(s.leastBitMethod(Integer.MAX_VALUE));
    }

    public int leastBitMethod(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
}