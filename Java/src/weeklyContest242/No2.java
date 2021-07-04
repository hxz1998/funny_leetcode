/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest242;

import java.util.Arrays;

public class No2 {
    public int minSpeedOnTime(int[] dist, double hour) {
        if (dist.length > Math.ceil(hour)) return -1;
        int left = 1, right = Integer.MAX_VALUE;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(dist, hour, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    private boolean check(int[] dist, double hour, int speed) {
        double cnt = 0.0;
        for (int i = 0; i < dist.length - 1; ++i) {
            cnt += (dist[i] + speed - 1) / speed;
        }
        cnt += (double) dist[dist.length - 1] / speed;
        return cnt <= hour;
    }

    public static void main(String[] args) {
        int[] dist = {1, 1, 100000};
        No2 no2 = new No2();
        System.out.println(no2.minSpeedOnTime(dist, 2.01));
    }
}
