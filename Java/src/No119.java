/*
 * Copyright (c) 9/4/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No119 {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();
        ans.add(1);
        if (rowIndex == 0) return ans;
        for (int i = 1; i <= rowIndex; ++i) {
            List<Integer> buffer = new ArrayList<>();
            buffer.add(ans.get(0));
            for (int idx = 1; idx <= ans.size() - 1; ++idx) buffer.add(ans.get(idx) + ans.get(idx - 1));
            buffer.add(ans.get(ans.size() - 1));
            ans = buffer;
        }
        return ans;
    }

    public static void main(String[] args) {
        No119 no119 = new No119();
        System.out.println(no119.getRow(3));
    }
}
