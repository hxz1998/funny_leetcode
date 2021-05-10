/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lccup2021;

import java.util.Comparator;
import java.util.PriorityQueue;

public class No3 {
    public int magicTower(int[] nums) {
        long life = 1;
        for (int num : nums) life += num;
        if (life <= 0) return -1;
        life = 1;
        int ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2 - o1);
        for (int num : nums) {
            if (num > 0) life += num;
            else {
                life += num;
                pq.add(-num);
                if (life <= 0) {
                    int pop = pq.poll();
                    life += pop;
                    ans++;
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {100, 100, 100, -250, -60, -140, -50, -50, 100, 150};
        No3 no3 = new No3();
        System.out.println(no3.magicTower(nums));
    }
}
