/*
 * Copyright (c) 8/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1155 {
    private static final int MOD = 1_000_000_007;

    public int numRollsToTarget(int d, int f, int target) {
        // 状态转移方程，dp[i][j] 表示投掷 i 个骰子，得到和为 j 的情况个数
        int[][] dp = new int[d + 1][target + 1];
        // 对所有使用了一个骰子得到的情况个数设置为 1，作为起始条件
        for (int i = 1; i <= Math.min(f, target); ++i) dp[1][i] = 1;
        // 从个数为 2 开始进行遍历
        for (int i = 2; i <= d; ++i) {
            // 从和为 i 开始进行遍历搜索，直到和为 target
            for (int j = i; j <= target; ++j) {
                // 剩余和从 k = 1 开始遍历，由于每一次只能最多增加 f，因此需要小于等于 f，而且不能为负，所以 j - k >= 0
                for (int k = 1; k <= f && j - k >= 0; ++k) {
                    // 累加起来所有可能的情况
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
        return dp[d][target];
    }

    public static void main(String[] args) {
        No1155 no1155 = new No1155();
        System.out.println(no1155.numRollsToTarget(1, 6, 3));
    }
}
