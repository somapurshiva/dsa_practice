import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Program {
    public int[] threeNumberSortHashMap(int[] array, int[] order) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int j : array) {
            countMap.putIfAbsent(j, 0);
            countMap.put(j, countMap.get(j) + 1);
        }
        int idx = 0;
        for (int key : order) {
            int count = countMap.get(key) != null ? countMap.get(key) : 0;
            while (count-- > 0)
                array[idx++] = key;
        }
        return array;
    }

    public int[] threeNumberSort(int[] array, int[] order) {
        int firstIdx = 0, secondIdx = 0, thirdIdx = array.length - 1;
        while(secondIdx <= thirdIdx) {
            if (array[secondIdx] == order[0]) {
                swap(array, secondIdx, firstIdx);
                firstIdx++;
                secondIdx++;
            } else if (array[secondIdx] == order[1])
                secondIdx++;
            else {
                swap(array, thirdIdx, secondIdx);
                thirdIdx--;
            }
        }
        return array;
    }

    private void swap(int[] array, int idxA, int idxB) {
        int temp = array[idxA];
        array[idxA] = array[idxB];
        array[idxB] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {7, 8, 9, 7, 8, 9, 9, 9, 9, 9, 9, 9};
        int[] order = {8, 7, 9};
        Program p = new Program();
        Arrays.stream(p.threeNumberSort(arr, order)).forEach(System.out::println);
    }
}
