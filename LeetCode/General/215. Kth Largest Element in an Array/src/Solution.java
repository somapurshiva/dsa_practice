import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
    public static void main(String[] args) {
        int[] nums = {3,2,1,5,6,4};
        Solution s = new Solution();
        System.out.println(s.findKthLargest(nums, 2));
    }

    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minPQ = new PriorityQueue<>(nums.length);
        for (Integer num : nums) {
            minPQ.add(num);
            if (minPQ.size() > k)
                minPQ.poll();
        }
        return minPQ.poll();
    }
}
