import java.util.*;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class Program {
    static class MinHeap {
        List<Integer> heap = new ArrayList<Integer>();

        public MinHeap(List<Integer> array) {
            heap = buildHeap(array);
        }

        public List<Integer> buildHeap(List<Integer> array) {
            // Sift down every element of the array. Leaf nodes will be automatically returning in first if stmt itself.
            int lastIdx = array.size() - 1;
            for (int i = getParentIdx(lastIdx); i >= 0; i--) {
                siftDown(i, lastIdx, array);
            }
            return array;
        }

        public void siftDown(int currentIdx, int endIdx, List<Integer> heap) {
            while (currentIdx <= endIdx) {
                int leftIdx = getLeftChildIdx(currentIdx);
                int rightIdx = getRightChildIdx(currentIdx);
                int swapIdx;
                if (leftIdx > endIdx)
                    return;
                if (rightIdx > endIdx)
                    swapIdx = leftIdx;
                else swapIdx = heap.get(leftIdx) < heap.get(rightIdx) ? leftIdx : rightIdx;
                if (heap.get(swapIdx) > heap.get(currentIdx)) return;

                Collections.swap(heap, currentIdx, swapIdx);
                currentIdx = swapIdx;
            }
        }

        public void siftUp(int currentIdx, List<Integer> heap) {
            while (currentIdx > 0) {
                int parentIdx = getParentIdx(currentIdx);
                if (heap.get(currentIdx) < heap.get(parentIdx))
                    Collections.swap(heap, currentIdx, parentIdx);
                else return;
                currentIdx = parentIdx;
            }
        }

        public int peek() {
            return this.heap.get(0);
        }

        public int remove() {
            Collections.swap(this.heap, 0, this.heap.size() - 1);
            int rootEle = this.heap.remove(this.heap.size() - 1);
            siftDown(0, this.heap.size() - 1, this.heap);
            return rootEle;
        }

        public void insert(int value) {
            this.heap.add(value);
            siftUp(this.heap.size() - 1, this.heap);
        }

        private int getLeftChildIdx(int currIdx) {
            return 2 * currIdx + 1;
        }

        private int getRightChildIdx(int currIdx) {
            return 2 * currIdx + 2;
        }

        private int getParentIdx(int currIdx) {
            return (currIdx - 1) / 2;
        }
    }

    public static void main(String[] args) {
        Program.MinHeap minHeap =
                new Program.MinHeap(
                        new ArrayList<Integer>(
                                Arrays.asList(48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41)));
        minHeap.insert(76);
        System.out.println(minHeap.peek() == -5);
        System.out.println(minHeap.remove() == -5);
        System.out.println(minHeap.peek() == 2);
        System.out.println(minHeap.remove() == 2);
        System.out.println(minHeap.peek() == 6);
    }
}
