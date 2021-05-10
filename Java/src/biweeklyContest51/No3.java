/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest51;

import java.util.Arrays;
import java.util.stream.Stream;

public class No3 {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        arr[0] = 1;
        for (int i = 1; i < arr.length; ++i) {
            if (Math.abs(arr[i] - arr[i - 1]) > 1) arr[i] = arr[i - 1] + 1;
        }
        return Arrays.stream(arr).max().getAsInt();
    }

}
