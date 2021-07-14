/*
 * Copyright (c) 7/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

/**
 * 给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。
 *
 * 示例 1：
 *
 * 输入: "code"
 * 输出: false
 * 示例 2：
 *
 * 输入: "aab"
 * 输出: true
 * 示例 3：
 *
 * 输入: "carerac"
 * 输出: true
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/palindrome-permutation
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class No266 {
    public boolean canPermutePalindrome(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) cnt[s.charAt(i) - 'a']++;
        int frequency = 0;
        for (int c : cnt) if (c % 2 == 1) frequency++;
        return frequency <= 1;
    }
}
