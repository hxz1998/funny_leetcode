/*
 * Copyright (c) 8/18/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No949 {
    public String largestTimeFromDigits(int[] arr) {
        int ans = -1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i != j) {
                    for (int k = 0; k < 4; ++k) {
                        if (i != k && j != k) {
                            for (int l = 0; l < 4; ++l) {
                                if (i != l && j != l && k != l) {
                                    int hour = arr[i] + arr[j] * 10;
                                    int minute = arr[k] + arr[l] * 10;
                                    if (hour < 24 && minute < 60) {
                                        ans = Math.max(ans, hour * 60 + minute);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans > 0 ? String.format("%02d:%02d", ans / 60, ans % 60) : "";
    }
}
