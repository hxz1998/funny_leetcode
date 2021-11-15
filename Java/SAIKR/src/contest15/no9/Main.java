/*
 * Copyright (c) 10/24/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package contest15.no9;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[][] matrix = new Integer[n][3];
        for (int i = 0; i < n; ++i) {
            matrix[i][0] = scanner.nextInt();
            matrix[i][1] = scanner.nextInt();
            matrix[i][2] = scanner.nextInt();
        }
    }
}
