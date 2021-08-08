/*
 * Copyright (c) 8/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.PriorityQueue;

public class No1353 {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0]);
        int ans = 0;
        int currentDay = 1;
        PriorityQueue<Integer> canJoin = new PriorityQueue<>();
        int idx = 0, n = events.length;
        while (idx < n || !canJoin.isEmpty()) {
            while (!canJoin.isEmpty() && canJoin.peek() < currentDay) canJoin.poll();
            while (idx < n && events[idx][0] <= currentDay) canJoin.add(events[idx++][1]);
            if (!canJoin.isEmpty() && canJoin.peek() >= currentDay) {
                canJoin.poll();
                ans++;
            }
            currentDay++;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
        No1353 no1353 = new No1353();
        System.out.println(no1353.maxEvents(events));
    }
}

