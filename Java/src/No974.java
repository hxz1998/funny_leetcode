/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No974 {
    public int subarraysDivByK(int[] A, int K) {
        Map<Integer, Integer> record = new HashMap<>();
        // sum 用来记录前缀和，ans 用来返回
        int sum = 0, ans = 0;
        // 将能够除尽的初始值赋为1
        record.put(0, 1);
        // 然后开始挨个遍历
        for (int item : A) {
            sum += item;
            // 纠正 Java 除余操作会导致负数的情况
            while (sum < 0) sum += K;
            // 然后记下来余数，接着去哈希表里面找一找有没有前面存在的已经是同样余数的序列了
            int mod = sum % K;
            int same = record.getOrDefault(mod, 0);
            // 有的话就加上这个次数
            ans += same;
            // 再把现在的次数 + 1
            record.put(mod, same + 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] A = {4, 5, 0, -2, -3, 1};
        No974 no974 = new No974();
        System.out.println(no974.subarraysDivByK(A, 5));
        A = new int[]{-1, -9, -4, 0};
        System.out.println(no974.subarraysDivByK(A, 9));
    }
}
