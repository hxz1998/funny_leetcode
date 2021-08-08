/*
 * Copyright (c) 8/6/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.LinkedList;
import java.util.Queue;

public class No847 {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        // 使用 1 << n 代表 n 个节点的状态，如果等于 1， 说明访问过了，否则就是没访问过
        boolean[][] visited = new boolean[n][1 << n];
        // 用来广度优先遍历的队列
        Queue<int[]> queue = new LinkedList<>();
        // 先把每一个节点的自身设置问访问过，并且放到队列中去，最后设置当前距离为 0
        for (int id = 0; id < n; ++id) {
            int mask = 1 << id;
            queue.add(new int[]{id, mask, 0});
            visited[id][mask] = true;
        }
        while (!queue.isEmpty()) {
            // 从队列中拿出来一个节点，开始进行广度优先搜索
            int[] tuple = queue.poll();
            int id = tuple[0], mask = tuple[1], dist = tuple[2];
            // 如果已经访问过所有的节点，又因为是广度优先遍历，所以可以直接返回当前的距离了
            if (mask == (1 << n) - 1) return dist;
            // 否则的话，就挨个遍历它相邻的节点
            for (int next : graph[id]) {
                // 找到当前 id 相邻节点 next 节点的状态
                int maskV = mask | (1 << next);
                // 如果没访问过 next 节点的 maskV 状态，就放到队列中，准备广度优先搜索
                if (!visited[next][maskV]) {
                    queue.add(new int[]{next, maskV, dist + 1});
                    visited[next][maskV] = true;
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        int[][] graph = {{1, 2, 3}, {0}, {0}, {0}};
        No847 no847 = new No847();
        System.out.println(no847.shortestPathLength(graph));
    }
}
