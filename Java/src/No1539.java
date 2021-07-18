/*
 * Copyright (c) 7/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No1539 {
    public int findKthPositive(int[] arr, int k) {
        List<Integer> list = new ArrayList<>();
        int kCopy = k, num = 1;
        for (int idx = 0; idx < arr.length; ) {
            if (num != arr[idx]) {
                list.add(num);
                kCopy--;
            } else if (num == arr[idx]) ++idx;
            num++;
        }
        while (kCopy > 0) {
            list.add(num++);
            kCopy--;
        }
        return list.get(k - 1);
    }

    public static void main(String[] args) {
        int[] num = {2, 3, 4, 7, 11};
        No1539 no1539 = new No1539();

        System.out.println(no1539.findKthPositive(num, 5));
    }
}
