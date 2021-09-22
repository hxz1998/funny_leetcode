/*
 * Copyright (c) 9/11/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No600 {
    private int ans = 1;
    public int findIntegers(int n) {
        dfs(1, n);
        return ans;
    }

    private void dfs(int curr, int n) {
        if (curr > n) return;
        ans++;
        if ((curr & 1) == 1) dfs(curr << 1, n);
        else {
            dfs(curr << 1, n);
            dfs((curr << 1) + 1, n);
        }
    }

    public static void main(String[] args) {
        No600 no600 = new No600();
        System.out.println(no600.findIntegers(5));
    }
}
