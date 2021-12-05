import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, ArrayLoc> freqMap = new HashMap<>(nums.length);
        int maxFreq = Integer.MIN_VALUE, prevMax;
        int minDeg = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (freqMap.get(nums[i]) == null)
                freqMap.put(nums[i], new ArrayLoc(i, 1));
            else freqMap.get(nums[i]).freq++;
            if (freqMap.get(nums[i]).freq >= maxFreq) {
                prevMax = maxFreq;
                maxFreq = freqMap.get(nums[i]).freq;
                int deg = i - freqMap.get(nums[i]).firstIdx + 1;
                if (prevMax != maxFreq)
                    minDeg = deg;
                else if (deg < minDeg)
                    minDeg = deg;
            }
        }
        return minDeg;
    }

    public static void main(String[] args) {
        int[] arr = {2,1,1,2,1,3,3,3,1,3,1,3,2};
        Solution s = new Solution();
        System.out.println(s.findShortestSubArray(arr));
    }
}

class ArrayLoc {
    int firstIdx;
    int freq;

    ArrayLoc(int firstIdx, int freq) {
        this.firstIdx = firstIdx;
        this.freq = freq;
    }
}
