/*
 * Copyright (c) 8/12/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lcp;

import java.util.PriorityQueue;

public class No30 {
    public int magicTower(int[] nums) {
        long sum = 0;
        for (int num : nums) sum += num;
        if (sum < 0) return -1;
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(((o1, o2) -> o2 - o1));
        int ans = 0;
        long life = 1;
        for (int num : nums) {
            if (num >= 0) life += num;
            else {
                life += num;
                priorityQueue.add(-num);
                if (life <= 0) {
                    life += priorityQueue.poll();
                    ans++;
                }
            }
        }
        return ans;
    }
}
