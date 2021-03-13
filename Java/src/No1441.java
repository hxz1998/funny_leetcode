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
        // 直接逐个检查 target 与当前 num 是否匹配
        // 如果匹配呢，就直接 push 一个，然后游标 ++
        // 如果不匹配，那么就 push + pop，然后游标不动
        for (int num = 1, index = 0; num <= n && index < target.length; ++num) {
            if (num == target[index]) {
                ans.add(PUSH);
                ++index;
            } else {
                ans.add(PUSH);
                ans.add(POP);
            }
        }
        return ans;
    }
/*    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        // num是产生的数字，index 是 target 数组的下标
        for (int num = 1, index = 0; num <= n && index < target.length; ++num) {
            // 不管是否符合要求，先把数和操作放进来
            stack.add(num);
            ans.add(PUSH);
            // 检查一下是否符合要求，如果不符合，那么就把栈顶元素弹出来，然后再加入Pop操作
            if (target[index] != stack.peek()) {
                stack.pop();
                ans.add(POP);
            } else index++; // 符合要求的话，就把游标往右移动一个
        }
        return ans;
    }*/

    public static void main(String[] args) {
        int[] target = new int[]{2, 3, 4};
        System.out.println(new No1441().buildArray(target, 4));
    }
}
