class Solution {
    public int missingNumber(int[] nums) {
        int missingNum = nums.length;
        for (int i = 0; i < nums.length; i++) {
            missingNum ^= i ^ nums[i];
        }
        return missingNum;
    }

    public static void main(String[] args) {
        int[] arr = new int[] {9,6,4,2,3,5,7,0,1};
        Solution s = new Solution();
        System.out.println(s.missingNumber(arr));
    }
}
