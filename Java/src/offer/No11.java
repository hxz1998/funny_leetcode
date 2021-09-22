/*
 * Copyright (c) 8/22/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

public class No11 {
    public int minArray(int[] numbers) {
        int n = numbers.length;
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right]) right = mid;
            else if (numbers[mid] > numbers[right]) left = mid + 1;
            else right--;
        }
        return numbers[left];
    }
}
