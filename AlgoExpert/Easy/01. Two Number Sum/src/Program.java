import java.util.HashSet;
import java.util.Set;

public class Program {
    public static int[] twoNumberSum(int[] array, int targetSum) {
        Set<Integer> bag = new HashSet<>(array.length);
        int[] retArr = new int[2];
        for (int i = 0; i < array.length; i++) {
            if (bag.contains(targetSum - array[i])) {
                retArr[0] = targetSum - array[i];
                retArr[1] = array[i];
                return retArr;
            }
            bag.add(array[i]);
        }
        return new int[0];
    }
}
