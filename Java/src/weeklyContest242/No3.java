/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest242;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class No3 {
    private int minJump, maxJump;
    private boolean[] can;


    public boolean canReach(String s, int minJump, int maxJump) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < s.length(); ++i) if (s.charAt(i) == '0') list.add(i);
        if (s.charAt(s.length() - 1) != '0') return false;
        int curr = 0;
        boolean[] dp = new boolean[s.length()];
        dp[0] = true;
        for (int i = 0; i < s.length(); ++i) {
            if (dp[i]) {
                for (; curr < s.length() && list.get(curr) <= list.get(i) + maxJump; ++curr) {
                    if (list.get(curr) >= list.get(i) + minJump) dp[curr] = true;
                }
            }
        }
        return dp[dp.length - 1];
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        System.out.println(no3.canReach("011010", 2, 3));
    }
/*    public boolean canReach(String s, int minJump, int maxJump) {
        this.minJump = minJump;
        this.maxJump = maxJump;
        can = new boolean[s.length()];
        Arrays.fill(can, true);
        char[] cs = s.toCharArray();
        int oneCount = 0, zeroCount = 0;
        for (char c : cs) if (c == '0') zeroCount++; else oneCount++;
        if (zeroCount == s.length()) return true;
        return check(s.toCharArray(), s.length() - 1, s.length() - 1);
    }

    private boolean check(char[] cs, int left, int right) {
        if (right < 0) return false;
        if (left <= 0 || right == 0) return true;
        for (int i = left; i <= right; ++i) {
            if (can[i] && cs[i] == '0' && check(cs, i - maxJump, i - minJump)) return true;
            can[i] = false;
        }
        return false;
    }*/
}
