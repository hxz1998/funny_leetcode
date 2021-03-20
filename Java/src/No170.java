import java.util.TreeMap;

/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */
class TwoSum {
    private TreeMap<Integer, Integer> count;

    /**
     * Initialize your data structure here.
     */
    public TwoSum() {
        count = new TreeMap<>();
    }

    /**
     * Add the number to an internal data structure..
     */
    public void add(int number) {
        count.put(number, count.getOrDefault(number, 0) + 1);
    }

    /**
     * Find if there exists any pair of numbers which sum is equal to the value.
     */
    public boolean find(int value) {
        for (int key : count.keySet()) {
            if ((2 * key == value) && (count.get(key) == 2)) return true;
            if (count.containsKey(value - key) && (key != value / 2)) return true;
        }
        return false;
    }
}

public class No170 {
    public static void main(String[] args) {
        TwoSum twoSum = new TwoSum();
        twoSum.add(0);
        twoSum.add(-1);
        twoSum.add(-1);
        twoSum.add(0);
        System.out.println(twoSum.find(1));

    }
}

