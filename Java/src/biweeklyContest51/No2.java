/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest51;

import java.util.PriorityQueue;

public class No2 {
    static class SeatManager {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();

        public SeatManager(int n) {
            for (int i = 1; i <= n; ++i) priorityQueue.add(i);
        }

        public int reserve() {
            return priorityQueue.poll();
        }

        public void unreserve(int seatNumber) {
            priorityQueue.offer(seatNumber);
        }
    }


}
