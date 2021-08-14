/*
 * Copyright (c) 8/9/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import com.sun.jdi.IntegerType;

import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;

public class No313 {
    public int nthSuperUglyNumber(int n, int[] primes) {
        Set<Long> set = new HashSet<>();
        PriorityQueue<Long> pq = new PriorityQueue<>();
        set.add(1L);
        pq.add(1L);
        int uglyNumber = 0;
        for (int i = 0; i < n; ++i) {
            long curr = pq.poll();
            uglyNumber = (int) curr;
            for (int prime : primes) {
                long next = curr * prime;
                if (set.contains(next)) continue;
                pq.add(next);
                set.add(next);
            }
        }
        return uglyNumber;
    }

    public static void main(String[] args) {
        int[] primes = {2, 7, 13, 19};
        No313 no313 = new No313();
        System.out.println(no313.nthSuperUglyNumber(12, primes));
    }
}
