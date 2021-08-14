/*
 * Copyright (c) 8/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class No003 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        PriorityQueue<int[]> pq = new PriorityQueue<>(((o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0]));
        for (int i = 0; i < n; ++i) {
            int v = sc.nextInt();
            int w = sc.nextInt();
            pq.offer(new int[]{v + w * 2, i + 1});
        }
        int[][] ans = new int[m][];
        for (int i = 0; i < m; ++i) ans[i] = pq.poll();
        Arrays.sort(ans, (Comparator.comparingInt(o -> o[1])));
        for (int i = 0; i < m; ++i) System.out.print(ans[i][1] + " ");
    }
}
