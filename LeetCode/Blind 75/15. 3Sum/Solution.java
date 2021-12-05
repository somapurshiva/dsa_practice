import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> retList = new ArrayList<>();
        // Sort the input array first
        Arrays.sort(nums);
        // Declare two pointers left & right. Left will be start from the next index of the current elements under consideration
        // right will start from the end of the array
        // At any point we will move these pointers to check if the total sum matches until they cross each other
        int leftPtr, rightPtr;
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i-1] == nums[i])
                continue;
            leftPtr = i + 1;
            rightPtr = nums.length - 1;
            while (leftPtr < rightPtr) {
                int currSum = nums[i] + nums[leftPtr] + nums[rightPtr];
                if (currSum == 0) {
                    retList.add(Arrays.asList(nums[i], nums[leftPtr], nums[rightPtr]));
                    leftPtr++;
                    rightPtr--;
                } else if (currSum < 0) {
                    // Left element has lower value, we can increment left ptr to get a higher value to go closer to 0
                    leftPtr++;
                } else {
                    rightPtr--;
                }
            }
        }
        return retList;
    }

    public static void main(String[] args) {
        int[] arr = {-1,0,1,2,-1,-4};
        Solution s = new Solution();
        System.out.println(s.threeSum(arr));
    }
}
