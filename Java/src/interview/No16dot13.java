/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.awt.*;
import java.util.Arrays;

public class No16dot13 {
    public double[] cutSquares(int[] square1, int[] square2) {
        if (square1[0] > square2[0]) return cutSquares(square2, square1);
        double mid1X = square1[0] + 1.0 * square1[2] / 2, mid1Y = square1[1] + 1.0 * square1[2] / 2;
        double mid2X = square2[0] + 1.0 * square2[2] / 2, mid2Y = square2[1] + 1.0 * square2[2] / 2;
        if (mid1X == mid2X)
            return new double[]{mid1X, square1[1], mid2X, Math.max(square2[1] + square2[2], square1[1] + square1[2])};
        if (mid1Y == mid2Y)
            return new double[]{square1[0], mid1Y, Math.max(square2[0] + square2[2], square1[0] + square1[2]), mid2Y};
        double k = (mid2Y - mid1Y) / (mid2X - mid1X);
        double b = mid1Y - k * mid1X;

        double x1, y1, x2, y2;
        if (Math.abs(k) <= 1) {
            x1 = square1[0];
            y1 = x1 * k + b;
            x2 = Math.max(square1[0] + square1[2], square2[0] + square2[2]);
            y2 = x2 * k + b;
        } else {
            y1 = Math.min(square1[1], square2[1]);
            x1 = (y1 - b) / k;
            y2 = Math.max(square1[1] + square1[2], square2[1] + square2[2]);
            x2 = (y2 - b) / k;
        }
        if (x1 < x2) return new double[]{x1, y1, x2, y2};
        else return new double[]{x2, y2, x1, y1};
    }
    /*class Solution {
        public double[] cutSquares(int[] square1, int[] square2) {
            if (square1[2] < square2[2]) return cutSquares(square2, square1);
            double mx1 = square1[0] + (double) square1[2] / 2;
            double my1 = square1[1] + (double) square1[2] / 2;
            // 中点2
            double mx2 = square2[0] + (double) square2[2] / 2;
            double my2 = square2[1] + (double) square2[2] / 2;
            if (mx1 == mx2)
                return new double[]{mx1, Math.min(square1[1], square2[1]), mx2, Math.max(square1[1] + square1[2], square2[1] + square2[2])};
            if (my1 == my2)
                return new double[]{Math.min(square1[0], square2[0]), my1, Math.max(square1[0] + square1[2], square2[0] + square2[2]), my2};
            double k = (my1 - my2) / (mx1 - mx2);
            double b = my1 - k * mx1;
            // 直线 y = kx + b
            double x1, x2, y1, y2;
            if (Math.abs(k) >= 1) {// 斜率绝对值大于等于1，先确定y，再找对应的x
                y1 = Math.min(square1[1], square2[1]);
                x1 = (y1 - b) / k;
                y2 = Math.max(square1[1] + square1[2], square2[1] + square2[2]);
                x2 = (y2 - b) / k;
            } else {// 斜率绝对值小于1，先确定x，再找对应的y
                x1 = Math.min(square1[0], square2[0]);
                y1 = x1 * k + b;
                x2 = Math.max(square1[0] + square1[2], square2[0] + square2[2]);
                y2 = x2 * k + b;
            }
            if (x1 < x2) return new double[]{x1, y1, x2, y2};
            if (x1 > x2) return new double[]{x2, y2, x1, y1};
            if (y1 <= y2) return new double[]{x1, y1, x2, y2};
            return new double[]{x2, y2, x1, y1};
        }
    }*/
}
