/*
 * Copyright (c) 8/2/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1336 {
    private static final int INF = Integer.MAX_VALUE / 2;

    private void Dijkstra(int[][] graph, int[] distance, boolean[] visited, int n, int threshold, int start) {
        distance[start] = 0;
        for (int i = 0; i < n; ++i) {
            int from = -1, minDistance = INF;
            for (int u = 0; u < n; ++u) {
                if (!visited[u] && distance[u] < minDistance) {
                    from = u;
                    minDistance = distance[u];
                }
            }
            if (from == -1) return;
            visited[from] = true;
            for (int to = 0; to < n; ++to) {
                if (!visited[to] && graph[from][to] != INF) {
                    distance[to] = Math.min(distance[from] + graph[from][to], distance[to]);
                }
            }
        }
    }

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] graph = new int[n][n];
        for (int i = 0; i < n; ++i) Arrays.fill(graph[i], INF);
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            graph[from][to] = edge[2];
            graph[to][from] = edge[2];
        }
        int idx = -1;
        int minCount = INF;
        for (int i = 0; i < n; ++i) {
            int[] distance = new int[n];
            Arrays.fill(distance, INF);
            boolean[] visited = new boolean[n];
            Dijkstra(graph, distance, visited, n, distanceThreshold, i);
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (distance[j] <= distanceThreshold && i != j) count++;
            }
            if (count <= minCount) {
                minCount = count;
                idx = i;
            }
        }
        return idx;
    }

    public static void main(String[] args) {
        int[][] edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
        No1336 no1336 = new No1336();
        System.out.println(no1336.findTheCity(4, edges, 4));
    }
}
