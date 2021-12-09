import java.util.Random;

public class Solution {
    private int[] nums;

    public int findKthLargest(int[] nums, int k) {
        this.nums = nums;
        int size = nums.length;
        return quickSelect(0, size - 1, size - k);
    }

    private int quickSelect(int left, int right, int kThSmallest) {
        // If there is only one element in the sub-array, that is the matching element. Return it.
        if (left == right)
            return nums[left];
        // Choose random pivot and try to match the pivot index generated with the requested kTh smallest position
        int pivotIdx = left + new Random().nextInt(right - left);
        pivotIdx = partition(left, right, pivotIdx);
        if (pivotIdx == kThSmallest)
            return nums[pivotIdx];
        else if (pivotIdx < kThSmallest)
            return quickSelect(pivotIdx + 1, right, kThSmallest);
        else return quickSelect(left, pivotIdx - 1, kThSmallest);
    }

    private int partition(int left, int right, int pivotIdx) {
        int pivot = nums[pivotIdx];
        // Move the pivot element to the end of the array and find the select index where the pivot has to be inserted so that elements to the left of pivot index are smaller than the pivot and those to the right are larger
        swap(right, pivotIdx);
        // Now that pivot has moved to the end, start from the beginning of array to find the insertion point
        int storeIdx = left;
        for (int i = left; i <= right; i++) {
            // If a given element is smaller than the pivot element, the store index should lie to the right of the element.
            // Thus swap the element with the store index which will be behind and move the store index one place ahead
            if (nums[i] < pivot) {
                swap(storeIdx, i);
                storeIdx++;
            }
        }
        // At the end of the loop, the store index would have reached the place where the current pivot can be placed
        // Return the index after swapping with right index
        swap(storeIdx, right);
        return storeIdx;
    }

    private void swap(int idxA, int idxB) {
        int temp = nums[idxA];
        nums[idxA] = nums[idxB];
        nums[idxB] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {3, 2, 1, 5, 6, 4};
        Solution s = new Solution();
        System.out.println(s.findKthLargest(arr, 2));
    }
}
