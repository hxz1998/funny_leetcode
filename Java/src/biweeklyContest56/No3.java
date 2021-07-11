/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest56;

public class No3 {
    public boolean sumGame(String num) {
        int n = num.length();
        int leftQ = 0, rightQ = 0;
        int sumLeft = 0, sumRight = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num.charAt(i) == '?') leftQ++;
            else sumLeft += num.charAt(i) - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            if (num.charAt(i) == '?') rightQ++;
            else sumRight += num.charAt(i) - '0';
        }
        int diff = sumLeft - sumRight;
        int diffQ = leftQ - rightQ;
        if (diff == 0 && diffQ == 0) return false;
        if (diff < 0 && diffQ < 0) return false;
        if (diff > 0 && diffQ > 0) return false;
        if (Math.abs(diff) < Math.abs(diffQ * 9) || Math.abs(diff) > Math.abs(diffQ * 9)) return true;
        else return false;
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        System.out.println(no3.sumGame("?3295???"));
    }

}
