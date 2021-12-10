import java.util.*;

class Program {

    public List<Integer> radixSort(List<Integer> array) {
        // If the array is empty or has only element, return it as its already sorted
        if (array.size() < 2)
            return array;
        // Find the Max number in the list to calculate the max digits of elements in the array
        int maxNum = Collections.max(array);
        int digit = 0;
        while (maxNum / Math.pow(10, digit) > 0) {
            countingSort(array, digit);
            digit++;
        }
        return array;
    }

    private void countingSort(List<Integer> array, int digit) {
        int[] countArr = new int[10];
        int[] sortArr = new int[array.size()];

        int divisor = (int) Math.pow(10, digit);
        // Populate count array first
        for (int currEle : array) {
            int base = (currEle / divisor) % 10;
            countArr[base]++;
        }

        // Update count array with adjacent sums
        for (int i = 1; i < countArr.length; i++) {
            countArr[i] += countArr[i-1];
        }

        // Now traverse the arry from right and fill the sortArr
        for (int i = array.size() - 1; i >= 0; i--) {
            int curEle = array.get(i);
            int base = (curEle / divisor) % 10;
            int loc = countArr[base]--;
            sortArr[loc - 1] = curEle;
        }

        // At this point sortArr will be sorted by the given digit place's values
        for (int i = 0; i < sortArr.length; i++) {
            array.set(i, sortArr[i]);
        }
    }

    public static void main(String[] args) {
        int[] arr = {8762, 654, 3008, 345, 87, 65, 234, 12, 2};
        Program p = new Program();
        System.out.println(p.radixSort(Arrays.asList(8762, 654, 3008, 345, 87, 65, 234, 12, 2)));
    }
}
