/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No138 {
    static class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }
    Map<Node, Node> mapper = new HashMap<>();

    public Node copyRandomList(Node head) {
        if (head == null) return null;
        if (!mapper.containsKey(head)) {
            Node node = new Node(head.val);
            mapper.put(head, node);
            node.next = copyRandomList(head.next);
            node.random = copyRandomList(head.random);
        }
        return mapper.get(head);
    }

    public static void main(String[] args) {
        Node node1 = new Node(3);
        Node node2 = new Node(3);
        Node node3 = new Node(3);
        node1.next = node2;
        node2.next = node3;
        node2.random = node1;
        No138 no138 = new No138();
        System.out.println(no138.copyRandomList(node1));
    }
}
