/*
 * Copyright (c) 9/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No96 {
    public int numTrees(int n) {
        int[] g = new int[n + 1];
        // size == 0 和 1 的时候，只能有一种方法
        g[0] = 1;
        g[1] = 1;
        // size 从 2 开始进行构建，直到 n
        for (int size = 2; size <= n; ++size) {
            // 以 i 为根节点进行树的构建，左半部分和右半部分是一个等价关系，使用笛卡尔积进行计算
            for (int i = 1; i <= size; ++i) {
                g[size] += g[i - 1] * g[size - i];
            }
        }
        return g[n];
    }

    public static void main(String[] args) {
        No96 no96 = new No96();
        System.out.println(no96.numTrees(3));
    }
}
