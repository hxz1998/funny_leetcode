/*
 * Copyright (c) 9/1/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.List;

public class No139 {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int idx = 0; idx < n; ++idx) {
            if (!dp[idx]) continue;
            for (String word : wordDict) {
                if (s.length() >= idx + word.length() && s.substring(idx, idx + word.length()).equals(word))
                    dp[idx + word.length()] = true;
            }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        No139 no139 = new No139();
        System.out.println(no139.wordBreak("leetcode", Arrays.asList("leet", "code")));
    }
}
