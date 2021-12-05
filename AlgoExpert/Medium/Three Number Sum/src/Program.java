import java.util.*;

public class Program {
    public static List<Integer[]> threeNumberSum(int[] array, int targetSum) {
        List<Integer[]> retList = new ArrayList<>();
        Arrays.sort(array);
        for (int idx = 0; idx < array.length; idx++) {
            int leftPtr = idx + 1;
            int rightPtr = array.length - 1;
            while (leftPtr < rightPtr) {
                int currSum = array[idx] + array[leftPtr] + array[rightPtr];
                if (currSum == targetSum) {
                    retList.add(new Integer[] {array[idx], array[leftPtr], array[rightPtr]});
                    leftPtr++;
                    rightPtr--;
                }
                else if (currSum < targetSum)
                    leftPtr++;
                else rightPtr--;
            }
        }
        return retList;
    }



    public static void main(String[] args) {
        int[] arr = new int[] { 12, 3, 1, 2, -6, 5, -8, 6 };
        List<Integer[]> retList = threeNumberSum(arr, 0);
        retList.forEach(intArr -> Arrays.stream(intArr).forEach(System.out::println));
    }
}
