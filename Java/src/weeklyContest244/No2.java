/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest244;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class No2 {
    public int reductionOperations(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        int min = Integer.MAX_VALUE;
        for (int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
            min = Math.min(min, num);
        }
        PriorityQueue<int[]> queue = new PriorityQueue<>((o1, o2) -> o2[0] - o1[0]);
        for (var entry : counter.entrySet()) queue.offer(new int[]{entry.getKey(), entry.getValue()});
        int times = 0;
        while (!queue.isEmpty() && queue.size() != 1) {
            var entry = queue.poll();
            times += entry[1];
            entry[0] = queue.peek()[0];
            int value = queue.poll()[1];
            entry[1] = entry[1] + value;
            queue.offer(entry);
        }
        return times;
    }

    public static void main(String[] args) {
        No2 no2 = new No2();
        int[] nums = {1,1,2,2,3};
        System.out.println(no2.reductionOperations(nums));
    }
}
