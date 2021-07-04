/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest247;

/**
 * while (left < n) {
 * while (right < n && check(count)) {
 * ans += right != left ? 1 : 0;
 * count ^= (1 << (word.charAt(right) - 'a'));
 * right++;
 * }
 * count ^= (1 << (word.charAt(left) - 'a'));
 * left++;
 * if (check(count)) ans += right != left ? 1 : 0;
 * }
 */
public class No3 {
    public long wonderfulSubstrings(String word) {
        int n = word.length();
        int ans = n;
        int left = 0, right = left + 1;
        int count = 0;
        while (left < n) {
            count ^= (1 << (word.charAt(left) - 'a'));
            while (right < n) {
                count ^= (1 << (word.charAt(right) - 'a'));
                if (check(count)) ans++;
                right++;
            }
            count ^= (1 << (word.charAt(left) - 'a'));
            left++;
            if (check(count) && left + 1 < right) ans++;
        }
        return ans;
    }

    private boolean check(int count) {
        return (count & (count - 1)) == 0;
    }

    public static void main(String[] args) {
        No3 no3 = new No3();
        System.out.println(no3.wonderfulSubstrings("aba"));
        System.out.println(no3.wonderfulSubstrings("aabb"));
        System.out.println(no3.wonderfulSubstrings("he"));
        System.out.println(no3.wonderfulSubstrings("ehaehcjjaafjdceac"));
    }
}
