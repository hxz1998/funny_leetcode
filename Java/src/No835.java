/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.awt.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class No835 {
    public int largestOverlap(int[][] A, int[][] B) {
        int size = A.length;
        List<Point> A2 = new ArrayList<>(), B2 = new ArrayList<>();
        // 首先记录下来点集中为 1 的点
        for (int i = 0; i < size * size; ++i) {
            if (A[i / size][i % size] == 1) A2.add(new Point(i / size, i % size));
            if (B[i / size][i % size] == 1) B2.add(new Point(i / size, i % size));
        }

        Set<Point> seen = new HashSet<>();
        Set<Point> best = new HashSet<>(B2);
        int ans = 0;
        // 然后逐个对为1的点进行偏移量检查
        for (Point a : A2) {
            for (Point b : B2) {
                // 用来保存偏移量的点
                Point delta = new Point(b.x - a.x, b.y - a.y);
                // 检查这个偏移量是否使用过了
                if (!seen.contains(delta)) {
                    seen.add(delta);
                    // 用来记录为1的点数
                    int candidate = 0;
                    for (Point p : A2) {
                        // 如果 A 中的点加上偏移后，在B中，那么就将用来记录1的点数自增
                        if (best.contains(new Point(p.x + delta.x, p.y + delta.y)))  candidate++;
                    }
                    ans = Math.max(ans, candidate);
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Point p1 = new Point(1, 1);
        Point p2 = new Point(1, 2);
        System.out.println(p1.equals(p2));
    }
}
