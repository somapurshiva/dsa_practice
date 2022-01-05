import java.util.*;

class Program {
    public static List<Integer> mergeSortedArrays(List<List<Integer>> arrays) {
        List<Integer> sortedList = new ArrayList<>();
        PriorityQueue<HeapItem> minHeap = new PriorityQueue<>(arrays.size());
        for (int i = 0; i < arrays.size(); i++) {
            List<Integer> currArr = arrays.get(i);
            minHeap.add(new HeapItem(currArr.get(0), i, 0));
        }
        while (!minHeap.isEmpty()) {
            HeapItem minItem = minHeap.poll();
            sortedList.add(minItem.num);
            if (minItem.elementIdx == arrays.get(minItem.arrayIdx).size() - 1)
                continue;
            int eleIdx = minItem.elementIdx;
            int arrIdx = minItem.arrayIdx;
            eleIdx++;
            minHeap.add(new HeapItem(arrays.get(arrIdx).get(eleIdx), arrIdx, eleIdx));
        }
        return sortedList;
    }
}

class HeapItem implements Comparable {
    int num;
    int arrayIdx;
    int elementIdx;

    HeapItem(int num, int arrayIdx, int elementIdx) {
        this.num = num;
        this.arrayIdx = arrayIdx;
        this.elementIdx = elementIdx;
    }

    @Override
    public int compareTo(Object o) {
        HeapItem that = (HeapItem) o;
        return this.num - that.num;
    }
}