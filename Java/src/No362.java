/*
 * Copyright (c) 8/10/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.LinkedList;
import java.util.Queue;

public class No362 {
    static class HitCounter {
        private Queue<Integer> timestamps;

        public HitCounter() {
            timestamps = new LinkedList<>();
        }

        public void hit(int timestamp) {
            timestamps.add(timestamp);
        }

        public int getHits(int timestamp) {
            if (timestamps.isEmpty()) return 0;
            int frontTime = timestamp - 300;
            while (!timestamps.isEmpty() && timestamps.peek() <= frontTime) {
                timestamps.poll();
            }
            return timestamps.size();
        }
    }
}
