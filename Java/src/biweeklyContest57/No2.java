/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest57;

import java.util.*;

public class No2 {
    public int smallestChair(int[][] times, int targetFriend) {
        // 没占用的
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        // 占用的
        Set<Integer> set = new HashSet<>();
        // 映射谁坐了哪个座位
        Map<Integer, Integer> mapper = new HashMap<>();
        int n = times.length;
        for (int num = 0; num < n; ++num) queue.offer(num);
        int[][] arrives = new int[n][2];
        int[][] leaves = new int[n][2];
        int start = Integer.MAX_VALUE, end = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            arrives[i][0] = times[i][0];
            arrives[i][1] = i;
            start = Math.min(start, times[i][0]);
            leaves[i][0] = times[i][1];
            leaves[i][1] = i;
            end = Math.max(end, times[i][1]);
        }
        Arrays.sort(arrives, Comparator.comparingInt(o -> o[0]));
        Arrays.sort(leaves, Comparator.comparingInt(o -> o[0]));
        int arrivesIdx = 0, leaveIdx = 0;

        for (int time = start; time <= end; ++time) {
            if (leaves[leaveIdx][0] <= time) {
                while (leaveIdx < n && leaves[leaveIdx][0] <= time) {
                    int id = leaves[leaveIdx][1];
                    int pos = mapper.get(id);
                    queue.offer(pos);
                    set.remove(pos);
                    mapper.remove(id);
                    ++leaveIdx;
                }
            }
            if (arrives[arrivesIdx][0] <= time) {
                while (arrivesIdx < n && arrives[arrivesIdx][0] <= time) {
                    int pos = queue.poll();
                    while (set.contains(pos)) pos = queue.poll();
                    if (arrives[arrivesIdx][1] == targetFriend) return pos;
                    mapper.put(arrives[arrivesIdx][1], pos);
                    set.add(pos);
                    ++arrivesIdx;
                }
            }
        }
        return -1;
    }
}
