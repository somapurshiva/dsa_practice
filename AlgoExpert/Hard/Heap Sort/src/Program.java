import java.util.*;

class Program {
    public static int[] heapSort(int[] array) {
        // Build the max heap using siftdowns
        int firstParentIdx = (array.length - 2) / 2;
        for (; firstParentIdx >= 0; firstParentIdx--) {
            siftDown(firstParentIdx, array.length - 1, array);
        }
        // Start a sortable array at endIdx i.e. with 0 elements to begin with
        // Keep popping from the max heap to the moving endIdx and siftdown the top element
        for (int endIdx = array.length - 1; endIdx > 0; endIdx--) {
            // Swap first element to endIdx and sift down the new top element
            swap(array, 0, endIdx);
            siftDown(0, endIdx-1, array);
        }
        return array;
    }

    private static void siftDown(int startIdx, int endIdx, int[] array) {
        while (startIdx <= endIdx) {
            int leftIdx = getLeftChildIdx(startIdx);
            int rightIdx = getRightChildIdx(startIdx);
            if (leftIdx > endIdx) return;
            int swapIdx;
            if (rightIdx > endIdx)
                swapIdx = leftIdx;
            else
                swapIdx = array[leftIdx] > array[rightIdx] ? leftIdx : rightIdx;
            if (array[swapIdx] > array[startIdx]) {
                swap(array, startIdx, swapIdx);
                startIdx = swapIdx;
            } else return;
        }
    }

    private static void swap(int[] arr, int idxA, int idxB) {
        int temp = arr[idxA];
        arr[idxA] = arr[idxB];
        arr[idxB] = temp;
    }

    private static int getLeftChildIdx(int currIdx) {
        return 2 * currIdx + 1;
    }

    private static int getRightChildIdx(int currIdx) {
        return 2 * currIdx + 2;
    }

    public static void main(String[] args) {
        int[] arr = {8, 5, 2, 9, 5, 6, 3};
        Arrays.stream(heapSort(arr)).forEach(System.out::println);
    }
}
