/*
 * Copyright (c) 7/18/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;

public class No16dot03 {
    private static final double ERROR = 1e-6;

    public double[] intersection(int[] start1, int[] end1, int[] start2, int[] end2) {
        if (start1[0] > end1[0] || (start1[0] == end1[0] && start1[1] > end1[1])) swap(start1, end1);
        if (start2[0] > end2[0] || (start2[0] == end2[0] && start2[1] > end2[1])) swap(start2, end2);
        if (start1[0] > start2[0]) {
            swap(start1, start2);
            swap(end1, end2);
        }

        Point p1 = new Point(start1[0], start1[1]);
        Point p2 = new Point(end1[0], end1[1]);
        Point p3 = new Point(start2[0], start2[1]);
        Point p4 = new Point(end2[0], end2[1]);

        if (p1.x == p2.x && p2.x == p3.x && p3.x == p4.x) {
            if (isBetween(p1, p3, p2)) return new double[]{p2.x, p2.y};
            else if (isBetween(p3, p1, p4)) return new double[]{p1.x, p1.y};
            else return new double[]{};
        }

        Line line1 = new Line(p1, p2);
        Line line2 = new Line(p3, p4);

        if (p1.x == p2.x) {
            return helper(p1, p2, line2, p3, p4);
        } else if (p3.x == p4.x) {
            return helper(p3, p4, line1, p3, p4);
        }

        // 两者斜率一样
        if (Math.abs(line1.slope - line2.slope) <= ERROR) {
            if (Math.abs(line1.yIntercept - line2.yIntercept) <= ERROR && isBetween(p1, p3, p2))
                return new double[]{p3.x, p3.y};
            else return new double[]{};
        }

        double x = (line2.yIntercept - line1.yIntercept) / (line1.slope - line2.slope);
        double y = x * line1.slope + line1.yIntercept;
        Point mid = new Point(x, y);
        if (isBetween(p1, mid, p2) && isBetween(p3, mid, p4)) return new double[]{x, y};
        else return new double[]{};
    }

    // 已知 start 和 end 的横坐标一样，求交点
    private double[] helper(Point start, Point end, Line line, Point otherStart, Point otherEnd) {
        double nx = start.x;
        double ny = nx * line.slope + line.yIntercept;
        Point np = new Point(nx, ny);
        if (isBetween(start, np, end) && isBetween(otherStart, np, otherEnd)) return new double[]{nx, ny};
        return new double[]{};
    }

    private boolean isBetween(Point start, Point middle, Point end) {
        return isBetween(start.x, middle.x, end.x) &&
                isBetween(start.y, middle.y, end.y);
    }

    private boolean isBetween(double start, double middle, double end) {
        if (start > end) {
            return middle <= start && middle >= end;
        } else {
            return middle >= start && middle <= end;
        }
    }

    private void swap(int[] lhs, int[] rhs) {
        int x = lhs[0];
        int y = lhs[1];
        lhs[0] = rhs[0];
        lhs[1] = rhs[1];
        rhs[0] = x;
        rhs[1] = y;
    }

    private static class Line {
        double slope = 0.0;     // 斜率
        double yIntercept = 0;  // Y 轴截距

        Line(Point start, Point end) {
            double deltaX = end.x - start.x;
            double deltaY = end.y - start.y;
            slope = deltaY / deltaX;
            yIntercept = end.y - slope * end.x;
        }
    }

    private static class Point {
        double x, y;

        Point(double x, double y) {
            setLocation(x, y);
        }

        void setLocation(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        /**
         * [0,0]
         * [0,1]
         * [0,0]
         * [0,-1]
         */
//        int[] start1 = {0, 0}, end1 = {0, 1}, start2 = {0, 0}, end2 = {0, -1};
//        No16dot03 no16dot03 = new No16dot03();
//        System.out.println(Arrays.toString(no16dot03.intersection(start1, end1, start2, end2)));
        /**
         * [0,0]
         * [1,-1]
         * [0,0]
         * [-1,1]
         */
//        int[] start1 = {0, 0}, end1 = {1, -1}, start2 = {0, 0}, end2 = {-1, 1};
//        No16dot03 no16dot03 = new No16dot03();
//        System.out.println(Arrays.toString(no16dot03.intersection(start1, end1, start2, end2)));
        /**
         * [1,0]
         * [1,1]
         * [-1,0]
         * [3,2]
         */
//        int[] start1 = {1, 0}, end1 = {1, 1}, start2 = {-1, 0}, end2 = {3, 2};
//        No16dot03 no16dot03 = new No16dot03();
//        System.out.println(Arrays.toString(no16dot03.intersection(start1, end1, start2, end2)));
        /**
         * [1,1]
         * [-1,1]
         * [1,0]
         * [-3,2]
         */
        int[] start1 = {0, 0}, end1 = {3, 3}, start2 = {1, 1}, end2 = {2, 2};
        No16dot03 no16dot03 = new No16dot03();
        System.out.println(Arrays.toString(no16dot03.intersection(start1, end1, start2, end2)));
    }
}
