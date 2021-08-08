/*
 * Copyright (c) 8/5/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class No802 {
    private enum Color {
        WHITE, GRAY, BLACK
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> ans = new ArrayList<>();
        Color[] colors = new Color[graph.length];
        Arrays.fill(colors, Color.WHITE);
        for (int start = 0; start < graph.length; ++start) {
            if (dfs(graph, colors, start)) ans.add(start);
        }
        return ans;
    }

    private boolean dfs(int[][] graph, Color[] colors, int start) {
        if (colors[start] != Color.WHITE) return colors[start] == Color.BLACK;
        colors[start] = Color.GRAY;
        for (int next : graph[start]) {
            if (!dfs(graph, colors, next)) return false;
        }
        colors[start] = Color.BLACK;
        return true;
    }
}
