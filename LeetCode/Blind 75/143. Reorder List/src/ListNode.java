public class ListNode {
    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public void reorderList(ListNode head) {
        // Step 1 -> Find middle of the list using slow and fast pointers
        // Step 2 -> Reverse the second part of the list
        // Step 3 -> Merge the two parts
    }
}