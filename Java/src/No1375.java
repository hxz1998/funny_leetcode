/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1375 {
    public int numTimesAllBlue(int[] light) {
        int n = light.length;
        int ans = 0, max = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            max = Math.max(max, light[i]);
            count++;
            if (count == max) ans++;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] light = {2, 1, 4, 3, 6, 5};
        No1375 no1375 = new No1375();
        System.out.println(no1375.numTimesAllBlue(light));
    }
}
