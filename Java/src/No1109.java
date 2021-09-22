/*
 * Copyright (c) 8/31/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1109 {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] ans = new int[n];
        for (int[] booking : bookings) {
            ans[booking[0] - 1] += booking[2];
            if (booking[1] < n) ans[booking[1]] -= booking[2];
        }
        for (int i = 1; i < n; ++i) ans[i] = ans[i - 1] + ans[i];
        return ans;
    }

    public static void main(String[] args) {
        int[][] bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
        No1109 no1109 = new No1109();
        System.out.println(Arrays.toString(no1109.corpFlightBookings(bookings, 5)));
    }
}
