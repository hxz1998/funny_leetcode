/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class No970 {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < 20 && Math.pow(x, i) <= bound; ++i) {
            for (int j = 0; j < 20 && Math.pow(y, j) <= bound; ++j) {
                int v = (int) Math.pow(x, i) + (int) Math.pow(y, j);
                if (v <= bound) set.add(v);
            }
        }
        return new ArrayList(set);
    }

    public static void main(String[] args) {
        No970 no970 = new No970();
        System.out.println(no970.powerfulIntegers(1, 2, 1000000).toString());
    }
}
