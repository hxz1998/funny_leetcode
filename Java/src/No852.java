/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No852 {
    public int peakIndexInMountainArray(int[] arr) {
        int left = 1;
        while (arr[left] > arr[left - 1]) left++;
        return left - 1;
    }
}
