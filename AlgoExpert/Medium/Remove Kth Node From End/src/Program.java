import java.util.*;

class Program {
    public static void removeKthNodeFromEnd(LinkedList head, int k) {
        LinkedList secPtr = head;
        LinkedList firstPtr = head;
        int count = 1;
        while (count <= k) {
            count++;
            secPtr = secPtr.next;
        }
        if (secPtr == null) {
            head.value = head.next.value;
            head.next = head.next.next;
            return;
        }
        while (secPtr.next != null) {
            firstPtr = firstPtr.next;
            secPtr = secPtr.next;
        }
        firstPtr.next = firstPtr.next.next;
    }

    static class LinkedList {
        int value;
        LinkedList next = null;

        public LinkedList(int value) {
            this.value = value;
        }
    }
}
