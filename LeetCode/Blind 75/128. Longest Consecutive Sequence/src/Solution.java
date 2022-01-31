import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numSet = new HashSet<>(nums.length);
        for (int num : nums)
            numSet.add(num);

        int longestStreak = 0;

        for (int num : nums) {
            if (!numSet.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.contains(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }

    public static void main (String[] args) {
        Solution s = new Solution();
        System.out.println(s.longestConsecutive(new int[]{ 100, 4, 200, 1, 3, 2 }));
        System.out.println(s.longestConsecutive(new int[]{0,3,7,2,5,8,4,6,0,1}));
    }
}