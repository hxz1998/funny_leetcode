/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class No301 {
    private int len = 0;
    private Set<String> ans = new HashSet<>();
    private char[] cs;

    public List<String> removeInvalidParentheses(String s) {
        len = s.length();
        cs = s.toCharArray();
        int leftRemove = 0, rightRemove = 0;
        for (char c : cs) {
            // 遇到左括号，就直接累加
            if (c == '(') leftRemove++;
            else if (c == ')') {
                // 如果已经被抵消完了，那么就说明需要删除额外的右括号了
                if (leftRemove == 0) rightRemove++;
                // 遇到右括号，而且左括号被抵消后剩余大于 0 个，因此可以先抵消掉一个
                else leftRemove--;
            }
        }
        dfs(0, 0, 0, leftRemove, rightRemove, new StringBuilder());
        return new ArrayList<>(ans);
    }

    private void dfs(int idx, int leftCount, int rightCount, int leftRemove, int rightRemove, StringBuilder path) {
        // 如果走到了字符串末尾，那么就进行判断是否已经是合法字符串了，如果是的话，就放到返回值中
        if (idx == len) {
            if (leftRemove == 0 && rightRemove == 0) ans.add(path.toString());
            return;
        }
        // 否则的话，就把当前遍历到的字符串拿出来
        char c = cs[idx];
        // 如果是左括号，而且还需要删除左括号，就把当前这个括号删掉，然后再深度优先搜索
        if (c == '(' && leftRemove > 0) dfs(idx + 1, leftCount, rightCount, leftRemove - 1, rightRemove, path);
        // 如果是右括号，而且还需要删除右括号，同上
        if (c == ')' && rightRemove > 0) dfs(idx + 1, leftCount, rightCount, leftRemove, rightRemove - 1, path);
        // 否则的话，就把当前这个字符放到字符串中，当作返回值之一的其中一部分
        path.append(c);
        // 如果不是左括号而且不是右括号，那么就直接继续深度优先搜索下一个，数值不改变
        if (c != '(' && c != ')') dfs(idx + 1, leftCount, rightCount, leftRemove, rightRemove, path);
        // 如果遇到了左括号，但是我们不删它，先记录下来已经看到了一个左括号 leftCount + 1，然后再深度优先搜索
        else if (c == '(') dfs(idx + 1, leftCount + 1, rightCount, leftRemove, rightRemove, path);
        // 如果碰到了右括号，而且满足左括号数量严格大于右括号数量，我们才对当前右括号进行保留再深度优先搜索
        else if (rightCount < leftCount) dfs(idx + 1, leftCount, rightCount + 1, leftRemove, rightRemove, path);
        // 回溯
        path.deleteCharAt(path.length() - 1);
    }
}
