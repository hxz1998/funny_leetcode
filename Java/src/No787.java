/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.PriorityQueue;

public class No787 {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] graphs = new int[n][n];
        for (int i = 0; i < flights.length; ++i) {
            graphs[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        pq.offer(new int[]{src, 0, K + 1});
        while (!pq.isEmpty()) {
            int[] front = pq.poll();
            int from = front[0];
            int price = front[1];
            int k = front[2];
            if (from == dst) return price;
            if (k > 0) {
                for (int i = 0; i < n; ++i) {
                    if (graphs[from][i] > 0)
                        pq.offer(new int[]{i, price + graphs[from][i], k - 1});
                }
            }
        }
        return -1;
    }
}
