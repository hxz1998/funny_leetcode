/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No969 {
    public List<Integer> pancakeSort(int[] arr) {
        List<Integer> ans = new ArrayList<>();
        for (int num = arr.length; num >= 1; --num) {
            int idx = 0;
            while (arr[idx] != num) ++idx;

            if (idx == num - 1) continue;
            else if (idx == 0) {
                reversal(arr, num);
                ans.add(num);
            } else {
                reversal(arr, num + 1);
                ans.add(num + 1);
                reversal(arr, num);
                ans.add(num);
            }
        }
        return ans;
    }

    private void reversal(int[] nums, int index) {
        int left = 0, right = index - 1;
        while (left < right) {
            int t = nums[left];
            nums[left++] = nums[right];
            nums[right--] = t;
        }
    }
}
