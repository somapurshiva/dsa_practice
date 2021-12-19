import java.util.*;

// Feel free to add new properties and methods to the class.
class Program {
    static class DoublyLinkedList {
        public Node head;
        public Node tail;

        public void setHead(Node node) {
            if (head == null) {
                head = node;
                tail = node;
            }
            else insertAtPosition(1, node);
        }

        public void setTail(Node node) {
            if (tail == null) setHead(node);
            else insertAfter(tail, node);
        }

        public void insertBefore(Node node, Node nodeToInsert) {
            if (nodeToInsert == head && nodeToInsert == tail) return;
            // Remove the node from the existing list
            remove(nodeToInsert);
            // Set the right pointers
            Node prevNode = node.prev;
            nodeToInsert.next = node;
            node.prev = nodeToInsert;
            if (prevNode != null) {
                prevNode.next = nodeToInsert;
                nodeToInsert.prev = prevNode;
            }
            // If head was pointing to node, head must be moved now to point to the new node
            if (head == node)
                head = nodeToInsert;
        }

        public void insertAfter(Node node, Node nodeToInsert) {
            if (nodeToInsert == head && nodeToInsert == tail) return;
            // Remove the node from the existing list
            remove(nodeToInsert);
            // Set the right pointers
            Node nextNode = node.next;
            nodeToInsert.prev = node;
            node.next = nodeToInsert;
            if (nextNode != null) {
                nextNode.prev = nodeToInsert;
                nodeToInsert.next = nextNode;
            }
            // If tail was pointing to node, tail must now point to the newly inserted node
            if (tail == node)
                tail = nodeToInsert;
        }

        public void insertAtPosition(int position, Node nodeToInsert) {
            Node currNode = head;
            if (position == 1 && head == null) {
                setHead(nodeToInsert);
                return;
            }
            int pos = 1;
            while (pos != position) {
                pos++;
                currNode = currNode.next;
            }
            insertBefore(currNode, nodeToInsert);
        }

        public void removeNodesWithValue(int value) {
            Node currNode = head;
            while (currNode != null) {
                Node remNode = currNode;
                currNode = currNode.next;
                if (remNode.value == value)
                    remove(remNode);
            }
        }

        public void remove(Node node) {
            Node prevNode = node.prev;
            Node nextNode = node.next;
            // If node is HEAD, HEAD should be moved to next node
            if (node == head)
                head = nextNode;
            // If node is a TAIL, TAIL should be moved to prev node
            if (node == tail)
                tail = prevNode;
            // Update the pointers on prev & next node if they are present
            if (prevNode != null)
                prevNode.next = node.next;
            if (nextNode != null)
                nextNode.prev = node.prev;
            node.next = null;
            node.prev = null;
        }

        public boolean containsNodeWithValue(int value) {
            Node currNode = head;
            while (currNode != null) {
                if (currNode.value == value)
                    return true;
                currNode = currNode.next;
            }
            return false;
        }

        public void printQueue() {
            Node currNode = head;
            while (currNode != tail) {
                System.out.print(currNode.value+" -> ");
                currNode = currNode.next;
            }
            System.out.println(currNode.value);
        }

        public void printHead() {
            System.out.print(head.value);
        }

        public void printTail() {
            System.out.print(tail.value);
        }
    }

    // Do not edit the class below.
    static class Node {
        public int value;
        public Node prev;
        public Node next;

        public Node(int value) {
            this.value = value;
        }
    }

    public static void main(String[] args) {
        DoublyLinkedList dl = new DoublyLinkedList();
        Node n4 = new Node(4);
        dl.setHead(new Node(5));
        dl.printQueue();
        dl.setHead(n4);
        dl.printQueue();
        dl.setHead(new Node(3));
        dl.printQueue();
        dl.setHead(new Node(2));
        dl.printQueue();
        dl.setHead(new Node(1));
        dl.printQueue();
        dl.setHead(n4);
        dl.printQueue();
        dl.setTail(new Node(6));
        dl.printQueue();

    }
}
