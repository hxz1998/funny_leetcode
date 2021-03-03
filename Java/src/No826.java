/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No826 {
    static class Point {
        int x = 0, y = 0;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int N = difficulty.length;
        Point[] jobs = new Point[N];
        for (int i = 0; i < N; ++i) {
            jobs[i] = new Point(difficulty[i], profit[i]);
        }
        Arrays.sort(jobs, (a, b) -> a.x - b.x);
        Arrays.sort(worker);
        int ans = 0, i = 0, best = 0;
        for (int skill : worker) {
            while (i < N && skill >= jobs[i].x) {
                best = Math.max(best, jobs[i++].y);
            }
            ans += best;
        }
        return ans;
    }
}
