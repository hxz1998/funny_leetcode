/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Iterator;
import java.util.Stack;

public class No71 {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        // 首先把路径根据 / 来分割
        String[] s = path.split("/");
        for (int i = 0; i < s.length; ++i) {
            // 根据题意，如果遇到了 . 和 "" 那么就直接跳过去
            if (s[i].equals(".") || s[i].equals("")) continue;
            // 如果遇到 .. 表示要向后跳一个目录了，就把栈顶元素弹出来
            else if (s[i].equals("..")) {
                // 不过要先检查一下是不是已经在根目录了
                if (!stack.empty()) stack.pop();
            } else stack.push(s[i]);    // 否则就直接把当前目录给压到栈中
        }
        Iterator<String> iter = stack.iterator();
        StringBuilder ans = new StringBuilder();
        // 挨个拼接目录
        while (iter.hasNext()) {
            String item = iter.next();
            ans.append("/");
            if (!item.equals("")) {
                ans.append(item);
            }
        }
        // 防止出现空目录
        return ans.toString().equals("") ? "/" : ans.toString();
    }

    public static void main(String[] args) {
        String path = "/home//foo/";
        No71 no71 = new No71();
        System.out.println(no71.simplifyPath(path));
        System.out.println(no71.simplifyPath("/../"));
    }
}
