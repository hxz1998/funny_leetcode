/*
 * Copyright (c) 8/10/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.LinkedList;
import java.util.Queue;

public class No346 {
    static class MovingAverage {
        private Queue<Integer> data;
        private int size = 0;
        private int sum = 0;

        public MovingAverage(int size) {
            this.size = size;
            data = new LinkedList<>();
        }

        public double next(int val) {
            if (data.size() >= size) {
                sum -= data.poll();
            }
            sum += val;
            data.add(val);
            return 1.0 * sum / data.size();
        }
    }

    public static void main(String[] args) {
        MovingAverage m = new MovingAverage(3);
        System.out.println(m.next(1));
        System.out.println(m.next(10));
        System.out.println(m.next(3));
        System.out.println(m.next(5));
    }
}
