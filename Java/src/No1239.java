/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No1239 {
    private int ans = 0;

    public int maxLength(List<String> arr) {
        List<Integer> masks = new ArrayList<>();
        for (String item : arr) {
            int mask = 0;
            for (char c : item.toCharArray()) {
                int offset = c - 'a';
                if (((mask >> offset) & 1) != 0) {
                    mask = 0;
                    break;
                }
                mask |= 1 << offset;
            }
            if (mask != 0) masks.add(mask);
        }
        backtrack(masks, 0, 0);
        return ans;
    }

    private void backtrack(List<Integer> masks, int pos, int mask) {
        if (pos == masks.size()) {
            ans = Math.max(ans, Integer.bitCount(mask));
            return;
        }
        if ((mask & masks.get(pos)) == 0) backtrack(masks, pos + 1, mask | masks.get(pos));
        backtrack(masks, pos + 1, mask);
    }
}
