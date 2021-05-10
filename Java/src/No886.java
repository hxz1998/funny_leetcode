/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No886 {
    private boolean isTwoColorable = true;

    public boolean possibleBipartition(int N, int[][] dislikes) {
        // 判断有没有环
        int[][] graph = new int[N + 1][N + 1];
        for (int[] edge : dislikes) {
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
        }

        boolean[] colors = new boolean[N + 1];
        // 如果有环的话，说明就不行
        boolean[] visited = new boolean[N + 1];

        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) dfs(graph, visited, colors, i);
            if (!isTwoColorable) return false;
        }
        return isTwoColorable;
    }

    private void dfs(int[][] graph, boolean[] visited, boolean[] colors, int start) {
        visited[start] = true;
        for (int i = 1; i < graph.length; ++i) {
            if (graph[start][i] == 0) continue;
            if (!visited[i]) {
                colors[i] = !colors[start];
                dfs(graph, visited, colors, i);
            } else if (colors[i] == colors[start]) isTwoColorable = false;
        }
    }

    public static void main(String[] args) {
        int[][] graph = {{1, 2}, {1, 3}, {2, 4}};
        No886 no886 = new No886();
        System.out.println(no886.possibleBipartition(4, graph));
    }
}
