/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;

public class No851 {
    private int[] quiet;
    private ArrayList<Integer>[] graph;
    private int[] ans;

    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int size = quiet.length;
        graph = new ArrayList[size];
        ans = new int[size];
        this.quiet = quiet;

        for (int i = 0; i < size; ++i) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : richer) {
            graph[edge[1]].add(edge[0]);
        }

        Arrays.fill(ans, -1);
        for (int node = 0; node < size; ++node) dfs(node);
        return ans;
    }

    private int dfs(int node) {
        if (ans[node] == -1) {
            ans[node] = node;
            for (int child : graph[node]) {
                int candidate = dfs(child);
                if (quiet[candidate] < quiet[ans[node]]) ans[node] = candidate;
            }
        }
        return ans[node];
    }
}
