/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest245;

public class No2 {
    public int maximumRemovals(String s, String p, int[] removable) {
        int left = 0, right = removable.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            char[] cs = s.toCharArray();
            for (int i = 0; i <= mid; ++i) cs[removable[i]] = ' ';
            if (check(cs, p)) left = mid + 1;
            else right = mid;
        }
        char[] cs = s.toCharArray();
        for (int i : removable) cs[i] = ' ';
        if (check(cs, p)) return removable.length;
        return left;
    }

    private boolean check(char[] cs, String p) {
        int idx = 0;
        for (char c : cs) {
            if (idx == p.length()) return true;
            if (c != ' ' && c == p.charAt(idx)) idx++;
        }
        return idx == p.length();
    }

    public static void main(String[] args) {
        No2 no2 = new No2();
        int[] removable = {3, 1, 0};
        System.out.println(no2.maximumRemovals("abcacb", "ab", removable));
    }
}
