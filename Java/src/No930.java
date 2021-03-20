/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class No930 {
    public int numSubarraysWithSum(int[] A, int S) {
        int size = A.length;
        int prefix = 0, ans = 0;
        Map<Integer, Integer> mapper = new TreeMap<>();
        mapper.put(0, 1);
        for (int num : A) {
            prefix += num;
            // 假设 x = prefix - S，那么 prefix - x = S，x 也就是更小的前缀和
            ans += mapper.getOrDefault(prefix - S, 0);
            // 把当前的前缀和放到累加哈希表里
            mapper.put(prefix, mapper.getOrDefault(prefix, 0) + 1);
        }
        return ans;
    }
    /*public int numSubarraysWithSum(int[] A, int S) {
        int size = A.length;
        int[] prefix = new int[size + 1];
        // 构建前缀和
        for (int i = 0; i < size; ++i) prefix[i + 1] = prefix[i] + A[i];
        Map<Integer, Integer> count = new HashMap<>();
        int ans = 0;
        for (int num : prefix) {
            // 检查 num 是否出现，num 就是前缀和 + S的结果，有的话就说明前面有一个前缀符合要求，就加上
            ans += count.getOrDefault(num, 0);
            // 记录下来前缀和
            count.put(num + S, count.getOrDefault(num + S, 0) + 1);
        }
        return ans;
    }*/

    public static void main(String[] args) {
        int[] A = {1, 0, 1, 0, 1};
        No930 no930 = new No930();
        System.out.println(no930.numSubarraysWithSum(A, 2));
        A = new int[]{0, 0, 0, 0, 0};
        System.out.println(no930.numSubarraysWithSum(A, 0));
    }
}
