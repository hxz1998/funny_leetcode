/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class No954 {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : arr) count.put(x, count.getOrDefault(x, 0) + 1);
        Integer[] arrTemp = new Integer[arr.length];
        for (int i = 0; i < arr.length; ++i) arrTemp[i] = arr[i];
        // 按照绝对值大小进行升序排序
        Comparator<Integer> cmp = Comparator.comparingInt(Math::abs);
        Arrays.sort(arrTemp, cmp);
        for (int x : arrTemp) {
            // 如果当前数字的剩余个数已经到 0 了，那么就跳过这次，不检查了
            if (count.get(x) == 0) continue;
            // 如果没减到零，但是 2 * x 已经没有了，那么就直接返回 false 好了
            if (count.getOrDefault(2 * x, 0) <= 0) return false;
            // 更新剩余的个数
            count.put(x, count.get(x) - 1);
            count.put(2 * x, count.get(2 * x) - 1);
        }
        return true;
    }

    private int abs(int num) {
        return Math.abs(num);
    }

    public static void main(String[] args) {
        int[] arr = {4, -2, 2, -4};
        No954 no954 = new No954();
        System.out.println(no954.canReorderDoubled(arr));
        System.out.println(-100 % 3);
    }
}
