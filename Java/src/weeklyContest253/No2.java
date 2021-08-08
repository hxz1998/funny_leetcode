/*
 * Copyright (c) 8/8/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest253;

import java.util.PriorityQueue;

public class No2 {
    public int minStoneSum(int[] piles, int k) {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(((o1, o2) -> o2 - o1));
        for (int num : piles) priorityQueue.add(num);
        for (int i = 0; i < k; ++i) {
            int pile = priorityQueue.poll();
            pile = pile - pile / 2;
            priorityQueue.add(pile);
        }
        int sum = 0;
        for (int pile : priorityQueue) sum += pile;
        return sum;
    }
}
