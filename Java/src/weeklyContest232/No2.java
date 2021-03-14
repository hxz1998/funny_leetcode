/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest232;

public class No2 {
    public int findCenter(int[][] edges) {
        int n = edges.length + 1;
        int[] nodes = new int[n + 1];
        // 记录每一个节点的度
        for (int[] edge : edges) {
            nodes[edge[0]]++;
            nodes[edge[1]]++;
        }
        // 找到度最大的节点
        int ans = 0, max = nodes[0];
        for (int i = 1; i < nodes.length; ++i) {
            if (max < nodes[i]) {
                ans = i;
                max = nodes[i];
            }
        }
        // 拥有最大度的节点就是答案
        return ans;
    }

    public static void main(String[] args) {
        int[][] edges = new int[][]{{1, 2}, {2, 3}, {4, 2}};
        No2 no2 = new No2();
        System.out.println(no2.findCenter(edges));
        edges = new int[][]{{1, 2}, {5, 1}, {1, 3}, {1, 4}};
        System.out.println(no2.findCenter(edges));
    }
}
