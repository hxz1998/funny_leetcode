/*
 * Copyright (c) 10/24/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package contest15.no2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] line = sc.nextLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);
        int[][] matrix = new int[11][n + 2];
        List<Integer> ret = new ArrayList<>();
        while (q-- > 0) {
            int opt = sc.nextInt();
            int a = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();
            int level = 1;
            if (opt == 1) {
                int k = sc.nextInt();
                while (a > 0) {
                    if ((a & 1) == 1) {
                        matrix[level][left] += k;
                        matrix[level][right + 1] -= k;
                    }
                    level++;
                    a >>= 1;
                }
            } else {
                int ans = 0;
                while (a > 0) {
                    if ((a & 1) == 1) {
                        ans += (right - left + 1) * matrix[level][left];
                        for (int i = left + 1; i <= right; ++i) {
                            ans += matrix[level][i];
                        }
                    }
                    level++;
                    a >>= 1;
                }
                ret.add(ans);
            }
        }
        for (int item : ret) System.out.println(item);
    }
}
