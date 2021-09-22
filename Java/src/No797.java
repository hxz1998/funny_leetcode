/*
 * Copyright (c) 8/25/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No797 {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int src = 0, dst = graph.length - 1;
        List<List<Integer>> paths = new ArrayList<>();
        List<Integer> buffer = new ArrayList<>();
        buffer.add(src);
        dfs(graph, paths, buffer, src, dst);
        return paths;
    }

    private void dfs(int[][] graph, List<List<Integer>> paths, List<Integer> buffer, int start, int dst) {
        if (start == dst) {
            List<Integer> copy = new ArrayList<>(buffer);
            paths.add(copy);
            return;
        }
        for (int next : graph[start]) {
            buffer.add(next);
            dfs(graph, paths, buffer, next, dst);
            buffer.remove(buffer.size() - 1);
        }
    }

    public static void main(String[] args) {
        int[][] graph = {{1, 2}, {3}, {3}, {}};
        No797 no797 = new No797();
        System.out.println(no797.allPathsSourceTarget(graph));
    }
}
