/*
 * Copyright (c) 9/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

public class No264 {

    public int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int[] factories = {2, 3, 5};
        PriorityQueue<Long> minHeap = new PriorityQueue<>((Comparator.comparingLong(o -> o)));
        minHeap.add(1L);
        Set<Long> visited = new HashSet<>();
        long uglyNumber = 0;
        while (n-- > 0){
            uglyNumber = minHeap.poll();
            for (int num : factories) {
                if (!visited.contains(num * uglyNumber)) {
                    visited.add(num * uglyNumber);
                    minHeap.add(num * uglyNumber);
                }
            }
        }
        return (int) uglyNumber;
    }

    public static void main(String[] args) {
        No264 no264 = new No264();
        System.out.println(no264.nthUglyNumber(10));
    }
}
