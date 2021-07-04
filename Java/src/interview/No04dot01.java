/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;

public class No04dot01 {
    public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
        // 用来标记是否已经访问过某个节点了
        boolean[] visited = new boolean[n];
        // 邻接表
        ArrayList[] edgeList = new ArrayList[n];
        // 构建邻接表
        for (int i = 0; i < n; ++i) edgeList[i] = new ArrayList<Integer>();
        for (int[] edge : graph) edgeList[edge[0]].add(edge[1]);
        // 使用队列来帮助广度优先查找
        Queue<Integer> queue = new ArrayDeque<>();
        // 先把起始节点放进来
        queue.offer(start);
        visited[start] = true;
        while (!queue.isEmpty()) {
            // 取出来当前层遍历的元素
            int node = queue.poll();
            // 对它的所有邻居进行检查
            for (int idx = 0; idx < edgeList[node].size(); ++idx) {
                int neighbor = (int) edgeList[node].get(idx);
                // 如果之前已经访问过该邻居了,那么就跳过去
                if (visited[neighbor]) continue;
                // 如果找到了,就直接返回 ture
                if (neighbor == target) return true;
                // 否则标记来过了,然后放到队列中去
                visited[neighbor] = true;
                queue.offer(neighbor);
            }
        }
        return false;
    }
}
