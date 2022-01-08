class Solution {
    int[] nums;
    int target;
    public int search(int[] nums, int target) {
        this.nums = nums;
        this.target = target;
        int n = nums.length;
        if (n == 1)
            return nums[0] == target ? 0 : -1;

        int rotatedIndex = findRotatedIndex(0, n-1);
        if (nums[rotatedIndex] == target)
            return rotatedIndex;
        if (rotatedIndex == 0)
            return search(0, n-1);
        if (target < nums[0])
            return search(rotatedIndex, n-1);
        else return search(0, rotatedIndex - 1);
    }

    public int search(int left, int right) {
        while (left <= right) {
            int pivot = (left+right)/2;
            if (nums[pivot] == target)
                return pivot;
            else if (nums[pivot] < target)
                left = pivot + 1;
            else right = pivot - 1;
        }
        return -1;
    }

    private int findRotatedIndex(int left, int right) {
        if (nums[left] < nums[right])
            return 0;
        while (left <= right) {
            int pivot = (left+right)/2;
            if (nums[pivot] > nums[pivot+1])
                return pivot + 1;
            else {
                if (nums[pivot] < nums[left])
                    right = pivot - 1;
                else left = pivot + 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        int[] arr = new int[] {8,9,2,3,4};
        Solution s = new Solution();
        System.out.println(s.searchOptimized(arr, 9));
    }

    public int searchOptimized(int[] nums, int target) {
        int start = 0, end = nums.length-1;
        while (start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
}