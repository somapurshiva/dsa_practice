import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

class Solution {
    private Map<Node, Node> visited = new HashMap<>();

    public Node cloneGraph(Node node) {
//        return dfs(node);
        return bfs(node);
    }

    private Node dfs(Node node) {
        if (node == null)
            return node;

        if (visited.containsKey(node)) {
            return visited.get(node);
        }

        Node clonedNode = new Node(node.val, new ArrayList<>());
        visited.put(node, clonedNode);
        for (Node n : node.neighbors) {
            clonedNode.neighbors.add(dfs(n));
        }
        return clonedNode;
    }

    private Node bfs(Node node) {
        if (node == null)
            return node;
        Node clonedNode = new Node(node.val, new ArrayList<>());

        Queue<Node> queue = new ArrayDeque<>();
        queue.add(node);
        visited.put(node, clonedNode);

        while (!queue.isEmpty()) {
            Node n = queue.poll();
            for (Node neighbor : n.neighbors) {
                if (!visited.containsKey(neighbor)) {
                    visited.put(neighbor, new Node(neighbor.val, new ArrayList<>()));
                    queue.add(neighbor);
                }
                visited.get(n).neighbors.add(visited.get(neighbor));
            }
        }

        return clonedNode;
    }
}