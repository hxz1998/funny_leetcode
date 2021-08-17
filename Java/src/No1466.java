/*
 * Copyright (c) 8/15/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class No1466 {
    public int minReorder(int n, int[][] connections) {
        List<List<Integer>> connectedIndex = new ArrayList<>();
        for (int i = 0; i < n; ++i) connectedIndex.add(new ArrayList<>());
        // 记录下来和 from 以及 to 相关的路径 idx
        for (int idx = 0; idx < connections.length; ++idx) {
            int from = connections[idx][0];
            int to = connections[idx][1];
            connectedIndex.get(from).add(idx);
            connectedIndex.get(to).add(idx);
        }
        Queue<Integer> queue = new LinkedList<>();
        int ans = 0;
        // 记录某条路径是否访问过了
        boolean[] visited = new boolean[connections.length];
        // 把根节点放进来
        queue.offer(0);
        while (!queue.isEmpty()) {
            // 记下来当前节点标号
            int curr = queue.poll();
            for (int idx : connectedIndex.get(curr)) {
                // 如果处理过当前路径，就没必要继续下面的过程
                if (visited[idx]) continue;
                visited[idx] = true;
                // 当前路径来的节点，以及下一个将要到的目标点
                int from = connections[idx][0];
                int to = connections[idx][1];
                // 如果当前节点作为来的节点出现，那么就需要修改了
                if (from == curr) ans += 1;
                // 修改这条路径
                from = (from == curr) ? to : from;
                queue.offer(from);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
        No1466 no1466 = new No1466();
        System.out.println(no1466.minReorder(6, connections));
    }
}
