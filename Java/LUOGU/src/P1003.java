/*
 * Copyright (c) 8/25/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

public class P1003 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] carpets = new int[n][4];
        for (int i = 0; i < n; ++i) {
            carpets[i][0] = sc.nextInt();
            carpets[i][1] = sc.nextInt();
            carpets[i][2] = sc.nextInt();
            carpets[i][3] = sc.nextInt();
        }
        int[] target = {sc.nextInt(), sc.nextInt()};
        int ans = -1;
        for (int idx = n - 1; idx >= 0; --idx) {
            int a = carpets[idx][0];
            int b = carpets[idx][1];
            int g = carpets[idx][2];
            int k = carpets[idx][3];
            if (a <= target[0] && a + g >= target[0] && b <= target[1] && b + k >= target[1]) {
                ans = idx + 1;
                break;
            }
        }
        System.out.println(ans);
    }
}
