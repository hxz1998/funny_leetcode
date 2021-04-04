/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class No76 {
    private Map<Character, Integer> origin;
    private Map<Character, Integer> count;

    public String minWindow(String s, String t) {
        origin = new HashMap<>();
        count = new HashMap<>();
        // 首先对 t 中的字符进行个数统计
        for (char c : t.toCharArray()) origin.put(c, origin.getOrDefault(c, 0) + 1);

        // left 是滑动窗口的左边界，right 是滑动窗口的右边界，ansLeft 是最终答案的左边界，ansRight 是最终答案的右边界
        int left = 0, right = 0, ansLeft = -1, ansRight = -1;
        int size = s.length();
        // len 用来记录滑动窗口最小的值是多少
        int len = Integer.MAX_VALUE;
        while (right < size) {
            char c = s.charAt(right);
            // 对窗口右边界进行读入，并将对应的字符个数进行累加和
            if (origin.containsKey(c)) count.put(c, count.getOrDefault(c, 0) + 1);
            // 检查一下当前两个哈希表中的值是否符合要求，而且要求左边界不能超过有边界
            while (check() && left <= right) {
                // 如果找到了更小的窗口，那么就进行更新操作
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    ansLeft = left;
                    ansRight = right + 1;
                }
                // 然后右移左边界，并吐出来之前左边界的字符统计个数
                if (origin.containsKey(s.charAt(left))) count.put(s.charAt(left), count.getOrDefault(s.charAt(left), 0) - 1);
                left++;
            }
            // 记得右移右边界，然后继续寻找
            right++;
        }
        // 如果答案的右边界没经过更新，说明没有找到符合要求的值，就直接返回空的好了，否则的话，就返回子字符串
        return ansRight == -1 ? "" : s.substring(ansLeft, ansRight);
    }

    private boolean check() {
        // 检查两个哈希表中的值是否符合要求
        for (Map.Entry<Character, Integer> entry : origin.entrySet()) {
            // 只要当前序列中某个字符的的个数小于要求的个数，就直接返回 false 就好了
            if (count.getOrDefault(entry.getKey(), 0) < entry.getValue()) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        No76 no76 = new No76();
        System.out.println(no76.minWindow("ADOBECODEBANC", "ABC"));
    }
}
