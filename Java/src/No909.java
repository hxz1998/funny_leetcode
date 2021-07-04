/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayDeque;
import java.util.Queue;

public class No909 {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        boolean[] visited = new boolean[n * n + 1];
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{1, 0});
        while (!queue.isEmpty()) {
            int[] position = queue.poll();
            for (int i = 1; i <= 6; ++i) {
                int next = position[0] + i;
                if (next > n * n) break;
                int[] rc = id2rc(next, n);
                if (board[rc[0]][rc[1]] != -1) {
                    next = board[rc[0]][rc[1]];
                }
                if (next == n * n) return position[1] + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(new int[]{next, position[1] + 1});
                }
            }
        }
        return -1;
    }

    private int[] id2rc(int id, int n) {
        int r = (id - 1) / n, c = (id - 1) % n;
        if (r % 2 == 1) c = n - c - 1;
        return new int[]{n - 1 - r, c};
    }
}
