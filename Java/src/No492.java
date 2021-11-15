/*
 * Copyright (c) 10/23/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No492 {
    public int[] constructRectangle(int area) {
        int[] ans = {};
        int mid = (int) Math.sqrt(area);
        for (int i = 1; i <= mid; ++i) {
            if (area % i == 0) ans = new int[]{area / i, i};
        }
        return ans;
    }

    public static void main(String[] args) {
        No492 no492 = new No492();
        System.out.println(Arrays.toString(no492.constructRectangle(4)));
    }
}
