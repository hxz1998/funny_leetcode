/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lcvscode;

import java.util.*;

public class No2 {
    public int halfQuestions(int[] questions) {
        int n = questions.length / 2;
        Map<Integer, Integer> mapper = new HashMap<>();
        for (int num : questions) mapper.put(num, mapper.getOrDefault(num, 0) + 1);
        Integer[] count = new Integer[mapper.size()];
        int idx = 0;
        for (Map.Entry<Integer, Integer> entry : mapper.entrySet()) count[idx++] = entry.getValue();
        Arrays.sort(count, Comparator.reverseOrder());
        int kinds = 0;
        idx = 0;
        while (n > 0) {
            kinds++;
            n -= count[idx++];
        }
        return kinds;
    }

    public static void main(String[] args) {
        int[] q = {13, 8, 3, 7, 5, 6, 11, 12, 3, 6, 6, 11};
        No2 no2 = new No2();
        System.out.println(no2.halfQuestions(q));
        q = new int[]{1, 5, 1, 3, 4, 5, 2, 5, 3, 3, 8, 6};
        System.out.println(no2.halfQuestions(q));
        q = new int[]{2, 1, 6, 2};
        System.out.println(no2.halfQuestions(q));
    }
}
