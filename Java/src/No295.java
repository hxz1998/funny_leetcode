/*
 * Copyright (c) 8/27/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.PriorityQueue;

public class No295 {
    private static class MedianFinder {
        private PriorityQueue<Integer> smaller, bigger;

        public MedianFinder() {
            smaller = new PriorityQueue<>(((o1, o2) -> o2 - o1));
            bigger = new PriorityQueue<>(((o1, o2) -> o1 - o2));
        }

        public void addNum(int num) {
            // 添加，调整
            // 数字来了，先添加进 smaller 中，然后看看 bigger 中最小的数是不是比 smaller 中最大的数还要小
            // 如果是的话，就把 smaller 中最大的数放到 bigger 中，把 bigger 中最小的数放到 smaller 中
            smaller.add(num);
            if (!bigger.isEmpty() && bigger.peek() < smaller.peek()) {
                int big = smaller.poll();
                int small = bigger.poll();
                bigger.add(big);
                smaller.add(small);
            }
            if (smaller.size() > bigger.size() + 1) bigger.add(smaller.poll());
        }

        public double findMedian() {
            if (smaller.isEmpty()) return 0.0;
            if (bigger.isEmpty()) return smaller.peek();
            if (bigger.size() == smaller.size()) return 1.0 * (bigger.peek() + smaller.peek()) / 2;
            if (smaller.size() > bigger.size()) return smaller.peek();
            return 0.0;
        }
    }

    public static void main(String[] args) {
        MedianFinder finder = new MedianFinder();
        finder.addNum(1);
        finder.addNum(2);
        System.out.println(finder.findMedian());
        finder.addNum(3);
        System.out.println(finder.findMedian());
    }
}
