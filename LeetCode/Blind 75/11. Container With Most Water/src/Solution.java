class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int left = 0;
        int right = height.length - 1;
        while (left < right) {
            int currArea = Math.min(height[left], height[right]) * (right - left);
            if (currArea > maxArea) {
                maxArea = currArea;
            }
            if (height[left] <= height[right])
                left++;
            else right--;
        }
        return maxArea;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.print(s.maxArea(new int[] {1,8,6,2,5,4,8,3,7}));
    }
}