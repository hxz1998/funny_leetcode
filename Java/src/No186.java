/*
 * Copyright (c) 7/31/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No186 {
    public void reverseWords(char[] s) {
        int n = s.length;
        if (n == 0) return;
        int left = 0, right = n - 1;
        while (left < right) {
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }
        for (left = 0, right = 0; right < n; ++left, ++right) {
            while (right < n && s[right] != ' ') ++right;
            // [left, right)
            int l = left, r = right - 1;
            while (l < r) {
                char t = s[l];
                s[l++] = s[r];
                s[r--] = t;
            }
            left = right;
            if (right == n) return;
        }
    }

    public static void main(String[] args) {
        char[] s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
        No186 no186 = new No186();
        no186.reverseWords(s);
        System.out.println(s);
    }
}
