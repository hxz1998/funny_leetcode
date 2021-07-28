/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No1213 {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        int idx1 = 0, idx2 = 0, idx3 = 0;
        List<Integer> list = new ArrayList<>();
        while (idx1 < arr1.length && idx2 < arr2.length && idx3 < arr3.length) {
            if (arr1[idx1] == arr2[idx2] && arr2[idx2] == arr3[idx3]) {
                list.add(arr1[idx1]);
                idx1++;
                idx2++;
                idx3++;
            } else {
                int min = Math.min(arr1[idx1], Math.min(arr2[idx2], arr3[idx3]));
                if (min == arr1[idx1]) idx1++;
                if (min == arr2[idx2]) idx2++;
                if (min == arr3[idx3]) idx3++;
            }
        }
        return list;
    }
}
