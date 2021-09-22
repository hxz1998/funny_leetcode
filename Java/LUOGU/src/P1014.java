/*
 * Copyright (c) 8/20/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Scanner;

public class P1014 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        boolean isTopToBottom = false;
        int currentSize = 1, totalSize = 1;
        while (totalSize < n) {
            currentSize += 1;
            totalSize += currentSize;
            isTopToBottom = !isTopToBottom;
        }
        int diff = totalSize - n;
        int num = currentSize;
        while (diff > 0) {
            num--;
            diff--;
        }
        if (isTopToBottom) System.out.println(num + "/" + (currentSize + 1 - num));
        else System.out.println((currentSize - num + 1) + "/" + num);
    }
}
