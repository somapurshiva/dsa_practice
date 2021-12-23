import java.util.*;

// Do not edit the class below except for the insertKeyValuePair,
// getValueFromKey, and getMostRecentKey methods. Feel free
// to add new properties and methods to the class.
class Program {
    static class LRUCache {
        int maxSize;
        int currentSize = 0;
        Map<String, DoublyLinkedListNode> cache = new HashMap<>();
        DoublyLinkedList list = new DoublyLinkedList();

        public LRUCache(int maxSize) {
            this.maxSize = Math.max(maxSize, 1);
        }

        public void insertKeyValuePair(String key, int value) {
            // If the key is already present in the hashmap, update the value on the node and move the node to the head
            DoublyLinkedListNode node;
            if (cache.containsKey(key)) {
                node = cache.get(key);
                node.value = value;
                list.setHeadTo(node);
            } else {
                currentSize++;
                node = new DoublyLinkedListNode(key, value);
                cache.put(key, node);
            }
            list.setHeadTo(node);
            if (currentSize > maxSize) {
                currentSize--;
                DoublyLinkedListNode tailNode = list.tail;
                list.removeTail();
                cache.remove(tailNode.key);
            }
        }

        public LRUResult getValueFromKey(String key) {
            LRUResult result;
            if (cache.containsKey(key)) {
                result = new LRUResult(true, cache.get(key).value);
                list.setHeadTo(cache.get(key));
            } else result = new LRUResult(false, -1);
            return result;
        }

        public String getMostRecentKey() {
            return list.head != null ? list.head.key : null;
        }
    }

    static class LRUResult {
        boolean found;
        int value;

        public LRUResult(boolean found, int value) {
            this.found = found;
            this.value = value;
        }

        @Override
        public String toString() {
            return "LRUResult{" +
                    "found=" + found +
                    ", value=" + value +
                    '}';
        }
    }

    static class DoublyLinkedListNode {
        String key;
        int value;
        DoublyLinkedListNode prev;
        DoublyLinkedListNode next;

        DoublyLinkedListNode(String key, int value) {
            this.key = key;
            this.value = value;
        }

        void removeBindings() {
            if (this.prev != null) {
                this.prev.next = this.next;
            }
            if (this.next != null) {
                this.next.prev = this.prev;
            }
        }
    }

    static class DoublyLinkedList {
        DoublyLinkedListNode head;
        DoublyLinkedListNode tail;

        void setHeadTo(DoublyLinkedListNode node) {
            if (this.head == node)
                return;
            if (head == null) {
                head = node;
                tail = node;
                return;
            } else if (this.tail == node) {
                removeTail();
            } else {
                node.removeBindings();
            }
            node.next = head;
            node.prev = null;
            head.prev = node;
            head = node;
        }

        void removeTail() {
            if (tail != null) {
                DoublyLinkedListNode tailNode = tail;
                tail = tailNode.prev;
                tailNode.removeBindings();
            }
        }
    }

    public static void main(String[] args) {
        LRUCache cache = new LRUCache(4);
        cache.insertKeyValuePair("a", 1);
        cache.insertKeyValuePair("b", 2);
        cache.insertKeyValuePair("c", 3);
        cache.insertKeyValuePair("d", 4);
        System.out.println("a: "+cache.getValueFromKey("a"));
        System.out.println("b: "+cache.getValueFromKey("b"));
        System.out.println("c: "+cache.getValueFromKey("c"));
        System.out.println("d: "+cache.getValueFromKey("d"));
        cache.insertKeyValuePair("e", 5);
        System.out.println("a: "+cache.getValueFromKey("a"));
        System.out.println("b: "+cache.getValueFromKey("b"));
        System.out.println("c: "+cache.getValueFromKey("c"));
        System.out.println("d: "+cache.getValueFromKey("d"));
        System.out.println("e: "+cache.getValueFromKey("e"));
    }
}
