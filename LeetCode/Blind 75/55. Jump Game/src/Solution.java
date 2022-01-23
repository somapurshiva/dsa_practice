class Solution {
    private enum Index { GOOD, BAD, UGLY }

    public boolean canJump(int[] nums) {
//        return backtrack(0, nums);
//        return dp(nums);
        return greedy(nums);
    }

    private static boolean backtrack(int position, int[] nums) {
        if (position == nums.length - 1)
            return true;
        int furthestDist = Math.min(position + nums[position], nums.length - 1);
        for (int i = furthestDist; i > position; i--) {
            if (backtrack(i, nums))
                return true;
        }
        return false;
    }

    private static boolean dp(int[] nums) {
        Index[] indices = new Index[nums.length];
        for (int i = 0; i < nums.length; i++)
            indices[i] = Index.UGLY;
        indices[nums.length-1] = Index.GOOD;
        for (int i = nums.length - 2; i >= 0; i--) {
            int furthestDist = Math.min(i + nums[i], nums.length - 1);
            for (int j = i + 1; j <= furthestDist; j++)
                if (indices[j] == Index.GOOD)
                    indices[i] = Index.GOOD;
        }
        return indices[0] == Index.GOOD;
    }

    private static boolean greedy(int[] nums) {
        int lastPos = nums.length - 1;
        for (int i = lastPos; i >= 0; i--) {
            if (i + nums[i] >= lastPos)
                lastPos = i;
        }
        return lastPos == 0;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.canJump(new int[] {3,2,1,0,4}));
    }
}