/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No849 {
    public int maxDistToClosest(int[] seats) {
        int size = seats.length;
        int[] left = new int[size], right = new int[size];
        Arrays.fill(left, size);
        Arrays.fill(right, size);

        for (int i = 0; i < size; ++i) {
            if (seats[i] == 1) left[i] = 0;
            else if (i > 0) left[i] = left[i - 1] + 1;
        }

        for (int i = size - 1; i >= 0; --i) {
            if (seats[i] == 1) right[i] = 0;
            else if (i < size - 1) right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < size; ++i) {
            if (seats[i] == 0) ans = Math.max(ans, Math.min(left[i], right[i]));
        }
        return ans;
    }
}
