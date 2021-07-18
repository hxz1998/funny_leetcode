/*
 * Copyright (c) 7/15/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class No253 {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        if (n == 0) return 0;
        Arrays.sort(intervals, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0]);
        PriorityQueue<Integer> allocator = new PriorityQueue<>(Comparator.comparingInt(o -> o));
        allocator.add(intervals[0][1]);
        for (int i = 1; i < n; ++i) {
            if (!allocator.isEmpty() && intervals[i][0] >= allocator.peek()) allocator.poll();
            allocator.add(intervals[i][1]);
        }
        return allocator.size();
    }

    public static void main(String[] args) {
        int[][] intervals = {{0, 30}, {5, 10}, {15, 20}};
        No253 no253 = new No253();
        System.out.println(no253.minMeetingRooms(intervals));
    }
}
