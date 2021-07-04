/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;
import java.util.Comparator;

public class No08dot13 {
    public int pileBox(int[][] boxes) {
        Arrays.sort(boxes, (o1, o2) -> o2[2] - o1[2]);
        int[] stackMap = new int[boxes.length];
        return create(boxes, null, 0, stackMap);
    }

    private int create(int[][] boxes, int[] box, int offset, int[] stackMap) {
        if (offset == boxes.length) return 0;
        int[] newBottom = boxes[offset];
        int heightWithBottom = 0;
        if (box == null || (newBottom[0] < box[0] && newBottom[1] < box[1] && newBottom[2] < box[2])) {
            if (stackMap[offset] == 0) {
                stackMap[offset] = create(boxes, newBottom, offset + 1, stackMap);
                stackMap[offset] += newBottom[2];
            }
            heightWithBottom = stackMap[offset];
        }
        int heightWithoutBottom = create(boxes, box, offset + 1, stackMap);
        return Math.max(heightWithoutBottom, heightWithBottom);
    }
}
