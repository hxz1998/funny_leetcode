/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class No961 {
    public int repeatedNTimes(int[] A) {
        Map<Integer, Integer> count = new HashMap<>();
        // 统计每一个数字出现的次数
        for (int x : A) count.put(x, count.getOrDefault(x, 0) + 1);
        // 从头检查看看哪一个数出现的次数符合要求，首先对
        int idx = A.length / 2;
        for (int key : count.keySet()) {
            // 找到后并返回
            if (count.get(key) == idx) return key;
        }
        return 0;
    }

    public static void main(String[] args) {
        int[] A = {2, 1, 2, 5, 3, 2};
        No961 no961 = new No961();
        System.out.println(no961.repeatedNTimes(A));
    }
}
