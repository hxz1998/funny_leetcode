/*
 * Copyright (c) 8/15/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

public class No006 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String message = sc.next();
        boolean foundM = false, foundT = false;
        int left = 0, right = n - 1;
        // 从前往后找到 M 同时，再找到 T
        while (left < right) {
            if (foundM && foundT) break;
            if (message.charAt(left) == 'M') foundM = true;
            if (foundM && message.charAt(left) == 'T') foundT = true;
            left++;
        }
        foundM = false;
        foundT = false;
        // 从后往前找到 T 同时，再找到 M
        while (right > left) {
            if (message.charAt(right) == 'T') foundT = true;
            if (foundT && message.charAt(right) == 'M') foundM = true;
            if (foundM && foundT) break;
            right--;
        }
        System.out.println(message.substring(left, right));
    }
}
