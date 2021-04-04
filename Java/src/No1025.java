/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1025 {
    public boolean divisorGame(int n) {
        if (n == 0 || n == 1) return false;
        // 多出来一个位置是为了方便操作
        boolean[] dp = new boolean[n + 1];
        // 先把前两个元素已知的结果保存下来
        dp[1] = false;
        dp[2] = true;
        // 然后从 3 开始逐个检查更新
        for (int i = 3; i <= n; ++i) {
            dp[i] = false;  // 先假设它是空的
            for (int j = 1; j < i; ++j)
                if (dp[j] && i % j == 0) {
                    dp[i] = true;
                    break;
                }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        No1025 no1025 = new No1025();
        System.out.println(no1025.divisorGame(2));
        System.out.println(no1025.divisorGame(3));
    }
}
