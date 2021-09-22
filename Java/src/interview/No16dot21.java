/*
 * Copyright (c) 8/26/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class No16dot21 {
    public int[] findSwapValues(int[] array1, int[] array2) {
        int sum1 = 0, sum2 = 0;
        Set<Integer> container = new HashSet<>();
        for (int num : array1) sum1 += num;
        for (int num : array2) {
            container.add(num);
            sum2 += num;
        }
        int diff = sum1 - sum2;
        if (diff % 2 != 0) return new int[]{};
        diff /= 2;
        for (int num : array1) if (container.contains(num - diff)) return new int[]{num, num - diff};
        return new int[]{};
    }

    public static void main(String[] args) {
        int[] array1 = {4, 1, 2, 1, 1, 2}, array2 = {3, 6, 3, 3};
        No16dot21 no16dot21 = new No16dot21();
        System.out.println(Arrays.toString(no16dot21.findSwapValues(array1, array2)));
    }
}
