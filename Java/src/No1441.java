/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class No1441 {
    private final static String PUSH = "Push";
    private final static String POP = "Pop";

    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        for (int num = 1, index = 0; num <= n && index < target.length; ++num) {
            stack.add(num);
            ans.add(PUSH);
            if (target[index] != stack.peek()) {
                stack.pop();
                ans.add(POP);
            } else index++;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] target = new int[]{2, 3, 4};
        System.out.println(new No1441().buildArray(target, 4));
    }
}
