import java.util.*;

class Program {
    // This is an input class. Do not edit.
    public static class LinkedList {
        int value;
        LinkedList next;

        LinkedList(int value) {
            this.value = value;
            this.next = null;
        }
    }

    public static LinkedList mergeLinkedListsIter(LinkedList headOne, LinkedList headTwo) {
        LinkedList p1 = headOne;
        LinkedList p2 = headTwo;
        LinkedList p1Prev = null;
        while (p1 != null && p2 != null) {
            if (p1.value < p2.value) {
                p1Prev = p1;
                p1 = p1.next;
            } else {
                if (p1Prev != null)
                    p1Prev.next = p2;
                p1Prev = p2;
                p2 = p2.next;
                p1Prev.next = p1;
            }
        }
        if (p2 != null) {
            p1Prev.next = p2;
        }
        return headOne.value < headTwo.value ? headOne : headTwo;
    }

    public static LinkedList mergeLinkedLists(LinkedList headOne, LinkedList headTwo) {
        recursiveMerge(headOne, headTwo, null);
        return headOne.value < headTwo.value ? headOne : headTwo;
    }

    private static void recursiveMerge(LinkedList p1, LinkedList p2, LinkedList p1Prev) {
        if (p1 == null) {
            p1Prev.next = p2;
            return;
        }

        if (p2 == null)
            return;

        if (p1.value < p2.value)
            recursiveMerge(p1.next, p2, p1);
        else {
            if (p1Prev != null)
                p1Prev.next = p2;
            LinkedList newP2 = p2.next;
            p2.next = p1;
            recursiveMerge(p1, newP2, p2);
        }
    }
}
