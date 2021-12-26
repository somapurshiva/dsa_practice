import java.util.*;

class Program {
    public static boolean hasSingleCycle(int[] array) {
        int currIdx = 0;
        int numOfEleVisited = 0;
        while (numOfEleVisited < array.length) {
            if (numOfEleVisited > 0 && currIdx == 0) return false;
            numOfEleVisited++;
            currIdx = getNextIdx(currIdx, array);
        }
        return currIdx == 0;
    }

    private static int getNextIdx(int currIdx, int[] array) {
        int jump = array[currIdx];
        int nextIdx = (jump + currIdx) % array.length;
        return nextIdx >= 0 ? nextIdx : nextIdx + array.length;
    }

    public static void main(String[] args) {
//        System.out.print(hasSingleCycle(new int[] {2,3,1,-4,-4,2}));
        System.out.print(hasSingleCycle(new int[] {0, 1, 1, 1, 1}));
    }
}
