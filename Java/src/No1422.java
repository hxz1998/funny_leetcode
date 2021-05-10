/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1422 {
    public int maxScore(String s) {
        int ans = 0;
        int zeroCount = 0, oneCount = 0;
        for (char c : s.toCharArray()) if (c == '1') oneCount++;

        for (int i = 0; i < s.length() - 1; ++i) {
            char c = s.charAt(i);
            if (c == '0') zeroCount++;
            else oneCount--;
            ans = Math.max(ans, oneCount + zeroCount);
        }
        return ans;
    }

    public static void main(String[] args) {
        No1422 no1422 = new No1422();
        System.out.println(no1422.maxScore("00"));
    }
}
