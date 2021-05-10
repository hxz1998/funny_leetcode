/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

class SummaryRanges {
    private Set<Integer> set;

    public SummaryRanges() {
        set = new TreeSet<>();
    }

    public void addNum(int val) {
        set.add(val);
    }

    public int[][] getIntervals() {
        List<int[]> ret = new ArrayList<>();
        Iterator<Integer> iterator = set.iterator();
        int begin = iterator.next(), end = iterator.next();
        while (iterator.hasNext()) {
            int t = iterator.next();
            if (t != end + 1) {
                ret.add(new int[]{begin, end});
                begin = t;
                end = begin;
            } else {
                end = t;
            }
        }
        return ret.toArray(new int[ret.size()][]);
    }
}

public class No352 {

}
