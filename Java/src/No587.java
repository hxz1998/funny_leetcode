/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;

public class No587 {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    // 求叉积
    private int orientation(Point p, Point q, Point r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }

    // 求距离，只不过没有开方而已
    private int distance(Point p, Point q) {
        return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
    }

    private Point bottomLeft(Point[] points) {
        Point ret = points[0];
        for (int i = 1; i < points.length; ++i) {
            if (points[i].y < ret.y) ret = points[i];
        }
        return ret;
    }

    public int[][] outerTrees(int[][] points) {
        int n = points.length;
        if (n == 1) return points;
        Point[] ps = new Point[n];
        for (int i = 0; i < n; ++i) ps[i] = new Point(points[i][0], points[i][1]);
        // 首先找到最下面的点（或者最左边的点）
        Point bottomLeft = bottomLeft(ps);

        // 然后排序，排序的依据是与最下面的点与当前点的逆时针夹角升序
        // 如果夹角相同，就按照点的 y 值升序排列
        Arrays.sort(ps, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                int diff = orientation(bottomLeft, o1, o2) - orientation(bottomLeft, o2, o1);
                if (diff == 0) return distance(bottomLeft, o1) - distance(bottomLeft, o2);
                else return diff > 0 ? 1 : -1;
            }
        });

        /*
         * 我们还需要考虑另一种重要的情况，
         * 如果共线的点在凸壳的最后一条边上，
         * 我们需要从距离初始点最远的点开始考虑起。
         * 所以，在将数组排序后，我们从尾开始遍历有序数组并将共线且朝有序数组尾部的点反转顺序，
         * 因为这些点是形成凸壳过程中尾部的点，所以在经过了这些处理以后，我们得到了求凸壳时正确的点的顺序。
         */
        int i = ps.length - 1;
        while (i >= 0 && orientation(bottomLeft, ps[ps.length - 1], ps[i]) == 0) --i;
        for (int l = i + 1, h = ps.length - 1; l < h; ++l, --h) {
            Point t = ps[l];
            ps[l] = ps[h];
            ps[h] = t;
        }
        Stack<Point> stack = new Stack<>();
        stack.push(ps[0]);
        stack.push(ps[1]);
        for (int j = 2; j < ps.length; ++j) {
            Point top = stack.pop();
            while (orientation(stack.peek(), top, ps[j]) > 0) top = stack.pop();
            stack.push(top);
            stack.push(ps[j]);
        }
        int[][] ret = new int[stack.size()][2];
        int idx = 0;
        while (!stack.isEmpty()) {
            ret[idx][0] = stack.peek().x;
            ret[idx++][1] = stack.pop().y;
        }
        return ret;
    }

    public static void main(String[] args) {
        int[][] points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
        No587 no587 = new No587();
        System.out.println(Arrays.toString(no587.outerTrees(points)));
    }
}
