import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> retList = new ArrayList<>();
        Arrays.sort(intervals, Comparator.comparing(arr -> arr[0]));
        int ptr = 1;
        int count = 0;
        int[] tempArr = new int[2];
        tempArr[0] = intervals[0][0];
        tempArr[1] = intervals[0][1];
        while (ptr < intervals.length) {
            if (intervals[ptr][0] < tempArr[1]) {
                count++;
                tempArr[0] = Math.min(intervals[ptr][0], tempArr[0]);
                tempArr[1] = Math.max(intervals[ptr][1], tempArr[1]);
            } else {
                retList.add(new int[] {tempArr[0], tempArr[1]});
                tempArr[0] = intervals[ptr][0];
                tempArr[1] = intervals[ptr][1];
            }
            ptr++;
        }
        retList.add(new int[] {tempArr[0], tempArr[1]});
        int[][] retArr = new int[retList.size()][];
        return retList.toArray(retArr);
    }

    public int[][] mergeWithLL(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparing(arr -> arr[0]));
        LinkedList<int[]> retList = new LinkedList<>();
        for (int[] interval : intervals) {
            if (retList.isEmpty() || retList.getLast()[1] < interval[0]) {
                retList.add(interval);
            } else {
                retList.getLast()[1] = Math.max(retList.getLast()[1], interval[1]);
            }
        }
        return retList.toArray(new int[retList.size()][]);
    }

    public static void main(String[] args) {
        int[][] intervals = new int[][] {
                {1,3},
                {2,6},
                {8,10},
                {15,18}
        };
        Solution s = new Solution();
        int[][] retArr = s.mergeWithLL(intervals);
        for (int[] arr : retArr) {
            System.out.println("["+arr[0]+","+arr[1]+"]");
        }
    }
}