/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class MaxPQ {
    private int idx = 0;
    private int size = 0;
    private int[] pq;

    private MaxPQ(int size) {
        this.size = size;
        this.pq = new int[size + 1];
    }

    private int size() {
        return idx;
    }

    private boolean isEmpty() {
        return idx == 0;
    }

    private void insert(int value) {
        pq[++idx] = value;
        swim(idx);
    }

    private int deleteMax() {
        int ret = pq[1];
        exch(1, idx--);
        pq[idx + 1] = 0;
        sink(1);
        return ret;
    }

    private void swim(int k) {
        while (k > 1 && less(k / 2, k)) {
            exch(k, k / 2);
            k = k / 2;
        }
    }

    private void sink(int k) {
        while (2 * k <= idx) {
            int j = 2 * k;
            if (j < idx && less(j, j + 1)) j++;
            if (!less(k, j)) break;
            exch(j, k);
            k = j;
        }
    }

    private boolean less(int i, int j) {
        return pq[i] < pq[j];
    }

    private void exch(int i, int j) {
        int t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }

    public static void main(String[] args) {
        int[] nums = {3, 5, 9, 1, 2};
        MaxPQ maxPQ = new MaxPQ(5);
        for (int i : nums) maxPQ.insert(i);
        while (!maxPQ.isEmpty()) {
            System.out.print(maxPQ.deleteMax() + " ");
        }
    }
}
