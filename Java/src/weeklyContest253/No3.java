/*
 * Copyright (c) 8/8/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest253;

public class No3 {
    public int minSwaps(String s) {
        int leftCnt = 0, rightCnt = 0;
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s.charAt(i) == ']') {
                if (leftCnt > 0) --leftCnt;
                else rightCnt++;
            } else leftCnt++;
        }
        int ans = (rightCnt + 1) / 2;
        leftCnt = 0;
        rightCnt = 0;
        for (int i = s.length() / 2; i < s.length(); ++i) {
            // 检查多少个 [ 没配对
            if (s.charAt(i) == '[') leftCnt++;
            else {
                if (leftCnt > 0) --leftCnt;
            }
        }
        return Math.max((leftCnt + 1) / 2, ans);
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        System.out.println(no3.minSwaps("][[]][][[][]"));
        System.out.println(no3.minSwaps("[[[]]]][][]][[]]][[[")); // 2
        System.out.println(no3.minSwaps("[[][][]]][")); // 1
    }
}
