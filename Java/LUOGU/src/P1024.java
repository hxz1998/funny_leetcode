/*
 * Copyright (c) 8/20/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

// WA
public class P1024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
        double A = b * b - 3 * a * c;
        double B = b * c - 9 * a * d;
        double C = c * c - 3 * b * d;
        double delta = B * B - 4 * A * C;
        if (A == B && A == 0) {
            double x = -1.0 * b / 3 / a;
            System.out.printf("%.2f %.2f %.2f", x, x, x);
        } else if (delta > 0) {
            // 这种情况包含复数，不予以考虑
        } else if (delta == 0) {
            double K = B / A;
            double x1 = -1.0 * b / a + K, x2 = -1.0 * K / 2;
            System.out.printf("%.2f %.2f %.2f", x1, x2, x2);
        } else {
            double T = (2 * A * b - 3 * a * B) / (2 * Math.sqrt(A * A * A));
            double theta = Math.acos(T);
            double x1 = (-1.0 * b - 2 * Math.sqrt(A) * Math.cos(theta / 3)) / (3 * a);
            double v = Math.sqrt(3) * Math.sin(theta / 3);
            double x2 = (-1.0 * b + Math.sqrt(A) * (Math.cos(theta / 3) + v)) / 3 / a;
            double x3 = (-1.0 * b + Math.sqrt(A) * (Math.cos(theta / 3) - v)) / 3 / a;
            System.out.printf("%.2f %.2f %.2f", x1, x2, x3);
        }
    }
}
