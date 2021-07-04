/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;

public class No08dot14 {
    private static int[][][] dp;
    private static char[] arr;

    private int getBooleanAns(int val1, int val2, char operator) {
        switch (operator) {
            case '&':
                return val1 & val2;
            case '^':
                return val1 ^ val2;
            case '|':
                return val1 | val2;
        }
        return -1;
    }

    private int helper(int start, int end, int result) {
        if (start == end) return arr[start] - '0' == result ? 1 : 0;
        if (dp[start][end][result] != -1) return dp[start][end][result];

        int ansCount = 0;
        for (int mid = start; mid < end; mid += 2) {
            char operator = arr[mid + 1];
            for (int i = 0; i <= 1; ++i) {
                for (int j = 0; j <= 1; ++j) {
                    if (getBooleanAns(i, j, operator) == result)
                        ansCount += helper(start, mid, i) * helper(mid + 2, end, j);
                }
            }
        }
        dp[start][end][result] = ansCount;
        return ansCount;
    }


    public int countEval(String s, int result) {
        int len = s.length();
        arr = s.toCharArray();
        dp = new int[len][len][2];
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return helper(0, len - 1, result);
    }

    // 暴力方法不可取，会超时
/*    public int countEval(String s, int result) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return stringToBoolean(s) == result? 1 : 0;
        int ways = 0;
        for (int i = 1; i < s.length(); i += 2) {
            char operator = s.charAt(i);
            String left = s.substring(0, i);
            String right = s.substring(i + 1);
            int leftTrue = countEval(left, 1);
            int leftFalse = countEval(left, 0);
            int rightTrue = countEval(right, 1);
            int rightFalse = countEval(right, 0);
            int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);

            int totalTrue = 0;
            if (operator == '^') totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
            else if (operator == '&') totalTrue = leftTrue * rightTrue;
            else if (operator == '|') totalTrue = leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;

            ways += result == 1 ? totalTrue : total - totalTrue;
        }
        return ways;
    }

    private int stringToBoolean(String s) {
        return Integer.parseInt(s);
    }*/
}
