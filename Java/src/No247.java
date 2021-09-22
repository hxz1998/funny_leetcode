/*
 * Copyright (c) 8/21/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class No247 {
    public List<String> findStrobogrammatic(int n) {
        return helper(n, n);
    }

    private List<String> helper(int n, int size) {
        if (size == 0) return new ArrayList<>(List.of(""));
        if (size == 1) return new ArrayList<>(List.of("1", "8", "0"));
        List<String> list = helper(n, size - 2);
        List<String> ret = new ArrayList<>();
        for (String s : list) {
            if (size != n) {
                ret.add("0" + s + "0");
            }
            ret.add("1" + s + "1");
            ret.add("6" + s + "9");
            ret.add("8" + s + "8");
            ret.add("9" + s + "6");
        }
        return ret;
    }
}
