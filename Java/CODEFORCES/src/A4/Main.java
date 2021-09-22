/*
 * Copyright (c) 8/19/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package A4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int weighted = scanner.nextInt();
        System.out.println(weighted % 2 == 0 && weighted > 2 ? "YES" : "NO");
    }
}

