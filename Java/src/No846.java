/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */


import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class No846 {
    public boolean isNStraightHand(int[] hand, int W) {
        // 首先检查个数是否符合要求，个数肯定要是 W 的整数倍
        if (hand.length % W != 0) return false;
        TreeMap<Integer, Integer> mapper = new TreeMap<>();
        // 统计每一个数字出现的个数
        for (int num : hand) mapper.put(num, mapper.getOrDefault(num, 0) + 1);
        // 然后去检查每一个 key ，是否有 key + 1, key + 2 ... k + w - 1
        // 如果有的话，就把 TreeMap 里面对应的记录值减去 1，如果没有的话，就直接返回 false 好了
        while (!mapper.isEmpty()) {
            int first = mapper.firstKey();
            for (int i = first; i < first + W; ++i) {
                if (!mapper.containsKey(i)) return false;
                int c = mapper.get(i);
                if (c == 1) mapper.remove(i);
                else mapper.put(i, mapper.get(i) - 1);
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int[] hand = new int[]{1, 2, 3, 6, 2, 3, 4, 7, 8};
        No846 test = new No846();
        System.out.println(test.isNStraightHand(hand, 3));
    }
}
