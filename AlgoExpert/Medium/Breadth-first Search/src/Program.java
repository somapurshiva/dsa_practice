import java.util.*;

class Program {
    // Do not edit the class below except
    // for the breadthFirstSearch method.
    // Feel free to add new properties
    // and methods to the class.
    static class Node {
        String name;
        List<Node> children = new ArrayList<>();

        public Node(String name) {
            this.name = name;
        }

        public List<String> breadthFirstSearch(List<String> array) {
            ArrayDeque<Node> queue = new ArrayDeque<>();
            queue.add(this);
            while (queue.size() > 0) {
                Node currNode = queue.poll();
                array.add(currNode.name);
                queue.addAll(currNode.children);
            }
            return array;
        }

        public Node addChild(String name) {
            Node child = new Node(name);
            children.add(child);
            return this;
        }
    }
}
