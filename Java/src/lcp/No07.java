/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lcp;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No07 {
    private int ans = 0;

    public int numWays(int n, int[][] relation, int k) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : relation) {
            List<Integer> list = graph.getOrDefault(edge[0], new ArrayList<>());
            list.add(edge[1]);
            graph.put(edge[0], list);
        }
        dfs(0, graph, 0, k, n - 1);
        return ans;
    }

    private void dfs(int start, Map<Integer, List<Integer>> graph, int steeps, int k, int end) {
        if (steeps == k) {
            if (start == end) ans++;
            return;
        }
        if (graph.get(start) == null) return;
        for (int next : graph.get(start)) dfs(next, graph, steeps + 1, k, end);
    }

    public static void main(String[] args) {
        int[][] edges = {{0, 2}, {2, 1}, {3, 4}, {2, 3}, {1, 4}, {2, 0}, {0, 4}};
        No07 no07 = new No07();
        System.out.println(no07.numWays(5, edges, 3));
    }
}
