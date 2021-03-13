/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import biweeklyContest47.No1;

import java.util.Iterator;
import java.util.Stack;

public class No1544 {
    public String makeGood(String s) {
        StringBuilder ans = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        int diff = 'a' - 'A';
        for (char c : s.toCharArray()) {
            if (!stack.empty() && (stack.peek() + diff == c || stack.peek() - diff == c)) {
                stack.pop();
            } else stack.push(c);
        }
        for (Character character : stack) ans.append(character);
        return ans.toString();
    }

    public static void main(String[] args) {
        System.out.println(new No1544().makeGood("leEeetcode"));
        System.out.println(new No1544().makeGood("abBAcC"));
        System.out.println(new No1544().makeGood("Pp"));
    }
}
