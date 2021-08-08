/*
 * Copyright (c) 8/2/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No1506 {
    static class Node {
        public int val;
        public List<Node> children;


        public Node() {
            children = new ArrayList<Node>();
        }

        public Node(int _val) {
            val = _val;
            children = new ArrayList<Node>();
        }

        public Node(int _val, ArrayList<Node> _children) {
            val = _val;
            children = _children;
        }
    }

    public Node findRoot(List<Node> tree) {
        int xorSum = 0;
        for (Node node : tree) {
            xorSum ^= node.val;
            for (Node children : node.children) xorSum ^= children.val;
        }
        for (Node node : tree) if (node.val == xorSum) return node;
        return null;
    }
}
