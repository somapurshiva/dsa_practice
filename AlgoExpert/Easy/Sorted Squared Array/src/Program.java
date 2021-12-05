import java.util.Arrays;

public class Program {
    public int[] sortedSquaredArray(int[] array) {
        int[] retArr = new int[array.length];
        int smallIdx = 0, largeIdx = array.length - 1;
        for (int idx = array.length - 1; idx >= 0; idx--) {
            int smallVal = array[smallIdx];
            int largeVal = array[largeIdx];
            if (Math.abs(smallVal) > Math.abs(largeVal)) {
                retArr[idx] = smallVal * smallVal;
                smallIdx++;
            } else {
                retArr[idx] = largeVal * largeVal;
                largeIdx--;
            }
        }
        return retArr;
    }

    public static void main(String[] args) {
        int[] arr = new int[] {-6, -5, -4, 1, 2, 3};
        Program p = new Program();
        int[] retArr = p.sortedSquaredArray(arr);
        Arrays.stream(retArr).forEach(System.out::println);
    }
}
