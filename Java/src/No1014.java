/*
 * Copyright (c) 8/30/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1014 {
    public int maxScoreSightseeingPair(int[] values) {
        int ans = 0, max = values[0];
        for (int j = 1; j < values.length; ++j) {
            ans = Math.max(ans, max + values[j] - j);
            max = Math.max(max, values[j] + j);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] values = {8, 1, 5, 2, 6};
        No1014 no1014 = new No1014();
        System.out.println(no1014.maxScoreSightseeingPair(values));
    }
}
