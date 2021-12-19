import java.util.*;

class Program {
    public static LinkedList reverseLinkedList(LinkedList head) {
        LinkedList fp = null;
        LinkedList sp = head;
        while (sp != null) {
            LinkedList tp = sp.next;
            sp.next = fp;
            fp = sp;
            sp = tp;
        }
        return fp;
    }

    static class LinkedList {
        int value;
        LinkedList next = null;

        public LinkedList(int value) {
            this.value = value;
        }
    }

    public static void main(String[] args) {
        LinkedList head = new LinkedList(0);
        head.next = new LinkedList(1);
        head.next.next = new LinkedList(2);
        head.next.next.next = new LinkedList(3);

        head = reverseLinkedList(head);
    }
}
