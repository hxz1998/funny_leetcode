/*
 * Copyright (c) 8/2/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class No743 {

    public int networkDelayTime(int[][] times, int n, int k) {
        int INF = Integer.MAX_VALUE / 2;
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; ++i) Arrays.fill(graph[i], INF);
        for (int[] edge : times) {
            int from = edge[0] - 1;
            int to = edge[1] - 1;
            int time = edge[2];
            graph[from][to] = time;
        }
        int[] dist = new int[n];
        Arrays.fill(dist, INF);
        dist[k - 1] = 0;
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; ++i) {
            int from = -1;
            for (int to = 0; to < n; ++to) {
                if (!visited[to] && (from == -1 || dist[from] > dist[to])) from = to;
            }
            visited[from] = true;
            for (int to = 0; to < n; ++to) {
                dist[to] = Math.min(dist[to], dist[from] + graph[from][to]);
            }
        }
        int ans = Arrays.stream(dist).max().getAsInt();
        return ans == INF ? -1 : ans;
    }

    public static void main(String[] args) {
        int[][] times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
        No743 no743 = new No743();
        System.out.println(no743.networkDelayTime(times, 4, 2));
    }
}
