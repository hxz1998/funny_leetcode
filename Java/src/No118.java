/*
 * Copyright (c) 9/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No118 {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(List.of(1));
        if (numRows == 1) return ans;
        for (int i = 1; i < numRows; ++i) {
            List<Integer> prev = ans.get(i - 1);
            List<Integer> buff = new ArrayList<>();
            buff.add(prev.get(0));
            for (int idx = 1; idx <= prev.size() - 1; ++idx) {
                buff.add(prev.get(idx) + prev.get(idx - 1));
            }
            buff.add(prev.get(prev.size() - 1));
            ans.add(buff);
        }
        return ans;
    }

    public static void main(String[] args) {
        No118 no118 = new No118();
        System.out.println(no118.generate(5));
    }
}
