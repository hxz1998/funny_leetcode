/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest232;

import java.util.PriorityQueue;

public class No3 {
    static class Triple implements Comparable {
        double diff;
        int x, y;

        Triple(double diff, int x, int y) {
            this.diff = diff;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Object o) {
            Triple t = (Triple) o;
            // Java默认是小根堆， 换成大根堆
            return -1 * (t.diff == diff ? t.x == x ? t.y - y : t.x - x : diff > t.diff ? 1 : -1);
        }
    }

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<Triple> priorityQueue = new PriorityQueue<>();
        double ans = 0;
        for (int[] c : classes) {
            int x = c[0], y = c[1];
            ans += (double) x / y;
            priorityQueue.add(new Triple(diff(x, y), x, y));
        }
        for (int i = 0; i < extraStudents; ++i) {
            Triple s = priorityQueue.poll();
            ans += s.diff;
            priorityQueue.add(new Triple(diff(s.x + 1, s.y + 1), s.x + 1, s.y + 1));
        }
        return ans / classes.length;
    }

    double diff(int lhs, int rhs) {
        return (double) (lhs + 1) / (rhs + 1) - (double) lhs / rhs;
    }

    public static void main(String[] args) {
        int[][] classes = new int[][]{{1, 2}, {3, 5}, {2, 2}};
        No3 no3 = new No3();
        System.out.println(no3.maxAverageRatio(classes, 2));
    }
}
