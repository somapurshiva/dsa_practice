import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Program {
    public int[] threeNumberSort(int[] array, int[] order) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < array.length; i++) {
            countMap.putIfAbsent(array[i], 0);
            countMap.put(array[i], countMap.get(array[i]) + 1);
        }
        int idx = 0;
        for (int key : order) {
            int count = countMap.get(key) != null ? countMap.get(key) : 0;
            while (count-- > 0)
                array[idx++] = key;
        }
        return array;
    }

    public static void main(String[] args) {
        int[] arr = {7, 8, 9, 7, 8, 9, 9, 9, 9, 9, 9, 9};
        int[] order = {8, 7, 9};
        Program p = new Program();
        Arrays.stream(p.threeNumberSort(arr, order)).forEach(System.out::println);
    }
}
