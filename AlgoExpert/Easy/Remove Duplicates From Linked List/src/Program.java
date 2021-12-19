import java.util.*;

class Program {
    // This is an input class. Do not edit.
    public static class LinkedList {
        public int value;
        public LinkedList next;

        public LinkedList(int value) {
            this.value = value;
            this.next = null;
        }
    }

    public LinkedList removeDuplicatesFromLinkedList(LinkedList linkedList) {
        LinkedList currPtr = linkedList;
        LinkedList nextPtr = linkedList.next;
        while (nextPtr != null) {
            if (nextPtr.value == currPtr.value) {
                // This is a duplicate. Remove the node
                currPtr.next = nextPtr.next;
                nextPtr = nextPtr.next;
            } else {
                // They are distinct values. Thus we can move both the ptrs fwd
                currPtr = currPtr.next;
                nextPtr = nextPtr.next;
            }
        }
        return linkedList;
    }
}
