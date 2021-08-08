/*
 * Copyright (c) 8/6/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No373 {
    private static class Node {
        private int i, j;

        Node(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }

    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> nums1[o1.i] + nums2[o1.j] - nums1[o2.i] - nums2[o2.j]);
        for (int i = 0; i < nums2.length; ++i) {
            pq.offer(new Node(0, i));
        }
        for (int i = 0; i < k && !pq.isEmpty(); ++i) {
            Node node = pq.poll();
            ans.add(Arrays.asList(nums1[node.i], nums2[node.j]));
            if (node.i + 1 < nums1.length) pq.add(new Node(node.i + 1, node.j));
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 1, 2};
        int[] nums2 = {1, 2, 3};
        No373 no373 = new No373();
        System.out.println(no373.kSmallestPairs(nums1, nums2, 10));
    }
}
