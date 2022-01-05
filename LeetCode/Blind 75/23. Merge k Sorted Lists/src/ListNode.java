import java.util.Comparator;
import java.util.PriorityQueue;

public class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummyNode = new ListNode(Integer.MIN_VALUE);
        ListNode ptr = dummyNode;
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>(Comparator.comparing(node -> node.val));
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null)
                minHeap.add(lists[i]);
        }
        while (!minHeap.isEmpty()) {
            ListNode minNode = minHeap.poll();
            ptr.next = minNode;
            ptr = ptr.next;
            if (minNode.next != null)
                minHeap.add(minNode.next);
        }
        return dummyNode.next;
    }
}