/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.List;

public class No469 {
    public boolean isConvex(List<List<Integer>> points) {
        int n = points.size();
        long prev = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points.get((i + 1) % n).get(0) - points.get(i).get(0);
            int y1 = points.get((i + 1) % n).get(1) - points.get(i).get(1);

            int x2 = points.get((i + 2) % n).get(0) - points.get((i + 1) % n).get(0);
            int y2 = points.get((i + 2) % n).get(1) - points.get((i + 1) % n).get(1);
            long curr = (long) x1 * y2 - (long) x2 * y1;
            if (curr != 0) {
                if (prev * curr < 0) return false;
                prev = curr;
            }
        }
        return true;
    }
}
