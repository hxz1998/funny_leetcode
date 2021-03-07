/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest47;

import java.util.ArrayList;
import java.util.Comparator;

public class No1 {
    public int nearestValidPoint(int x, int y, int[][] points) {
        ArrayList<Point> arrayList = new ArrayList<>();
        // 对每一个符合要求的点进行存储
        for (int idx = 0; idx < points.length; ++idx) {
            int[] point = points[idx];
            if (point[0] == x || point[1] == y) arrayList.add(new Point(point[0], point[1], idx));
        }
        // 排序，其相对大小与指定的 [x, y] 点计算曼哈顿距离来判断
        arrayList.sort(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return distance(o1, x, y) - distance(o2, x, y);
            }
        });
        // 最后检查返回值
        return arrayList.isEmpty() ? -1 : arrayList.get(0).idx;
    }

    private int distance(Point p, int x, int y) {
        return Math.abs(p.x - x) + Math.abs(p.y - y);
    }

    static class Point {
        // x, y 就是原来的坐标轴
        // idx 是在原来数组中的下标
        int x, y;
        int idx;

        Point(int x, int y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
        }
    }

    public static void main(String[] args) {
        int[][] points = new int[][]{{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
        System.out.println(new No1().nearestValidPoint(3, 4, points));
        points = new int[][]{{2, 3}};
        System.out.println(new No1().nearestValidPoint(3, 4, points));
    }
}
