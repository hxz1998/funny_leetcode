/*
 * Copyright (c) 7/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.LinkedList;
import java.util.Queue;

public class No17dot09 {
    public int getKthMagicNumber(int k) {
        Queue<Long> queue3 = new LinkedList<>();
        Queue<Long> queue5 = new LinkedList<>();
        Queue<Long> queue7 = new LinkedList<>();
        queue3.add(1L);
        long val = 0;
        for (int i = 0; i < k; ++i) {
            long val3 = queue3.isEmpty() ? Integer.MAX_VALUE : queue3.peek();
            long val5 = queue5.isEmpty() ? Integer.MAX_VALUE : queue5.peek();
            long val7 = queue7.isEmpty() ? Integer.MAX_VALUE : queue7.peek();
            val = Math.min(val3, Math.min(val5, val7));
            if (val == val3) {
                queue3.remove();
                queue3.add(3 * val);
                queue5.add(5 * val);
            } else if (val == val5) {
                queue5.remove();
                queue5.add(5 * val);
            } else queue7.remove();
            queue7.add(val * 7);
        }
        return (int) val;
    }

    public static void main(String[] args) {
        No17dot09 no17dot09 = new No17dot09();
//        System.out.println(no17dot09.getKthMagicNumber(1));
//        System.out.println(no17dot09.getKthMagicNumber(2));
//        System.out.println(no17dot09.getKthMagicNumber(3));
//        System.out.println(no17dot09.getKthMagicNumber(4));
//        System.out.println(no17dot09.getKthMagicNumber(5));
//        System.out.println(no17dot09.getKthMagicNumber(6));
        System.out.println(no17dot09.getKthMagicNumber(643));
    }
}
