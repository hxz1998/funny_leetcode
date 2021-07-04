/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest248;

public class No3 {
    private static final int MOD = 1_000_000_007;

    public int countGoodNumbers(long n) {
        if (n == 1) return 5;
        else if (n == 0) return 4;
        int ans = n / 2 == 0 ? 1 : 5;
        return ans * ((int) (Math.pow(countGoodNumbers(n / 2), 2) % MOD));
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        System.out.println(no3.countGoodNumbers(4));
        System.out.println(no3.countGoodNumbers(3));
        System.out.println(no3.countGoodNumbers(Integer.MAX_VALUE));
        System.out.println(no3.countGoodNumbers(50) == 564908303);
        System.out.println(no3.countGoodNumbers(1924) == 805821919);
        System.out.println(no3.countGoodNumbers(4606) == 478500968);
        System.out.println(no3.countGoodNumbers(452418) == 516626249);
        System.out.println(no3.countGoodNumbers(806166225460393L) == 643535977);
        System.out.println(no3.countGoodNumbers(806166225460393L));
        System.out.println(no3.countGoodNumbers(100_000_000_000_099L));
    }
}
