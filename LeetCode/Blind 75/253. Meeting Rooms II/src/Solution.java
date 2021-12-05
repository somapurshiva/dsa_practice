import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
    public int minMeetingRooms(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        PriorityQueue<int[]> roomsList = new PriorityQueue<>(intervals.length, Comparator.comparingInt(a -> a[1]));
        // First meeting will always require a new room. Hence, add it to the room list
        roomsList.add(intervals[0]);
        // For other meetings, iterate and check if any meeting has gotten over so that that room can be occupied by current meeting. Else assign a new meeting room
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= roomsList.peek()[1]) {
                // The earliest ending meeting in some room has ended. Hence, that room can be declared as vacant and taken out of the list
                roomsList.poll();
            }
            // Now add the current meeting to the rooms list, if the previous meeting was over, it would have been removed from the list anyway
            roomsList.add(intervals[i]);
        }
        return roomsList.size();
    }

    public int minMeetingRoomsUsingPtrs(int[][] intervals) {
        int[] start = new int[intervals.length];
        int[] end = new int[intervals.length];
        int numRooms = 0, startPtr = 0, endPtr = 0;
        for (int i = 0; i < intervals.length; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        while (startPtr < intervals.length) {
            if (start[startPtr] >= end[endPtr]) {
                // Some meeting has ended, we can free the room and look for next meeting that will end
                numRooms--;
                endPtr++;
            }
            // In any case whether the previous room got vacated or not, we need a room to hold meeting and look for next meeting req in the queue
            startPtr++;
            numRooms++;
        }
        return numRooms;
    }

    public static void main(String[] args) {
        int[][] arr = {
//                {0,6}, {15,20}, {5,10}, {11,16}
//                {7,10}, {2,4}
//                {0,30}, {5,10}, {15,20}
//                {5,10},{10,15},{15,20},{20,30}
//                {1,5},{8,9},{8,9}
                {1,10},{2,7},{3,19},{8,12},{10,20},{11,30}
        };
        Solution s = new Solution();
        System.out.println(s.minMeetingRoomsUsingPtrs(arr));
    }
}
