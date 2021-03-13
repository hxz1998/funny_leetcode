/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Stack;

public class No1081 {
    public String smallestSubsequence(String s) {
        int[] count = new int[26];
        char[] chars = s.toCharArray();
        for (char c : chars) count[c - 'a']++;
        boolean[] visited = new boolean[26];
        Stack<Character> stack = new Stack<>();
        StringBuilder ans = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (!visited[c - 'a']) {
                while (!stack.isEmpty() && stack.peek() > c) {
                    if (count[stack.peek() - 'a'] > 0) {
                        visited[stack.peek() - 'a'] = false;
                        stack.pop();
                    } else break;
                }
                visited[c - 'a'] = true;
                stack.push(c);
            }
            count[c - 'a']--;
        }
        for (char c : stack) ans.append(c);
        return ans.toString();
    }

    public static void main(String[] args) {
        String s = "bcabc";
        No1081 no1081 = new No1081();

        System.out.println(no1081.smallestSubsequence(s));
    }
}
