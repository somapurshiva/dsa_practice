import java.util.*;

class Program {
    public static int maxSubsetSumNoAdjacent(int[] array) {
        if (array.length == 0)
            return -1;
        else if (array.length == 1)
            return array[0];
        int second = array[0];
        int first = Math.max(second, array[1]);
        for (int i = 2; i < array.length; i++) {
            int current = Math.max(first, second + array[i]);
            second = first;
            first = current;
        }
        return first;
    }
}
