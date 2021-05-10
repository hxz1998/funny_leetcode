/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest236;

import java.util.ArrayList;
import java.util.PriorityQueue;

class MKAverage {
    private int m, k;
    private ArrayList<Integer> list = new ArrayList<>();
    private PriorityQueue<Integer> maxHeap = new PriorityQueue<>((o1, o2) -> o2 - o1);
    private PriorityQueue<Integer> minHeap = new PriorityQueue<>((o1, o2) -> o1 - o2);

    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;
    }

    public void addElement(int num) {
        list.add(num);

    }

    public int calculateMKAverage() {
        if (list.size() < m) return -1;
        maxHeap.addAll(list.subList(list.size() - m, list.size() - 1));
        minHeap.addAll(list.subList(list.size() - m, list.size() - 1));
        for (int i = 0; i < k; ++i) {
            maxHeap.remove(minHeap.poll());
            maxHeap.poll();
        }
        list = new ArrayList<>();
        list.addAll(maxHeap);
        int sum = 0;
        for (int item : list) sum += Math.round(1.0 * item / list.size());
        return sum;
    }
}

public class No4 {

}
