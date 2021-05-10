/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No7 {
    public int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && pop > 7)) return 0;
            if (ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && pop < -8)) return 0;
            ans = ans * 10 + pop;
        }
        return ans;
    }

    public static void main(String[] args) {
        No7 no7 = new No7();
        System.out.println(no7.reverse(123));
        System.out.println(no7.reverse(120));
        System.out.println(no7.reverse(0));
        System.out.println(no7.reverse(-123));
        System.out.println(no7.reverse(1534236469));

        System.out.println(Integer.MIN_VALUE / 10);
    }
}
