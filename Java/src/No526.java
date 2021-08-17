/*
 * Copyright (c) 8/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No526 {
    private int cnt = 0;

    private void calculate(int n, int pos, boolean[] visited) {
        // 如果将要处理的位置已经到了边界上，那么直接增加返回值就好了
        if (pos > n) ++cnt;
        // 从 1 到 n 挨个尝试放置数字
        for (int i = 1; i <= n; ++i) {
            // 如果没用过 i， 而且能够满足要求，就放下来，继续递归搜索
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(n, pos + 1, visited);
                visited[i] = false;
            }
        }
    }

    public int countArrangement(int n) {
        // visited 表示哪一个数字用过了
        calculate(n, 1, new boolean[n + 1]);
        return cnt;
    }

    public static void main(String[] args) {
        No526 no526 = new No526();
        System.out.println(no526.countArrangement(2));
    }
}
