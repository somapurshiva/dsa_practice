class Solution {
    public int findMin(int[] nums) {
        if (nums.length == 1 || nums[0] < nums[nums.length-1])
            return nums[0];
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int pivot = (low + high)/2;
            if (pivot > 0 && nums[pivot-1] > nums[pivot])
                return nums[pivot];
            if (pivot < nums.length - 1 && nums[pivot] > nums[pivot+1])
                return nums[pivot+1];
            if (nums[pivot] > nums[0]) low = pivot + 1;
            else high = pivot - 1;
        }
        return nums[0];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.findMin(new int[] {2,1}));
    }
}