/*
 * Copyright (c) 7/31/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No426 {
    static class Node {
        public int val;
        public Node left;
        public Node right;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, Node _left, Node _right) {
            val = _val;
            left = _left;
            right = _right;
        }
    }

    private List<Node> nodes;

    public Node treeToDoublyList(Node root) {
        nodes = new ArrayList<>();
        if (root == null) return null;
        inorder(root);
        Node dummyHead = new Node(0), curr = dummyHead;
        for (Node node : nodes) {
            curr.right = node;
            node.left = curr;
            curr = node;
        }
        dummyHead.right.left = curr;
        curr.right = dummyHead.right;
        return dummyHead.right;
    }

    private void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        nodes.add(root);
        inorder(root.right);
    }
}
