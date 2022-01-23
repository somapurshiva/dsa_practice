import java.util.LinkedList;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        LinkedList<int[]> retList = new LinkedList<>();
        int ptr = 0;
        // First add all the intervals that start before the start time of new interval
        while (ptr < intervals.length && intervals[ptr][0] <= newInterval[0])
            retList.add(intervals[ptr++]);
        // Now merge the new interval
        if (retList.isEmpty() || retList.getLast()[1] < newInterval[0]) {
            retList.add(newInterval);
        } else {
            int[] interval = retList.removeLast();
            interval[1] = Math.max(interval[1], newInterval[1]);
            retList.add(interval);
        }
        // Finally, add the remaining intervals and merge them
        while (ptr < intervals.length) {
            if (retList.getLast()[1] >= intervals[ptr][0]) {
                retList.getLast()[1] = Math.max(retList.getLast()[1], intervals[ptr][1]);
            } else {
                retList.add(intervals[ptr]);
            }
            ptr++;
        }
        return retList.toArray(new int[][]{});
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        s.insert(new int[][]{ {1,2}, {3,5}, {6,7}, {8,10}, {12,16} }, new int[] {4,8});
    }
}