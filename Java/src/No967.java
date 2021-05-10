/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No967 {
    private List<Integer> numbers = new ArrayList<>();

    public int[] numsSameConsecDiff(int n, int k) {
        for (int i = 1; i <= 9; ++i) {
            if (i + k >= 10 && i - k < 0) continue;
            dfs(new StringBuilder(i), k, n);
        }
        int[] ans = new int[numbers.size()];
        for (int i = 0; i < numbers.size(); ++i) ans[i] = numbers.get(i);
        return ans;
    }

    private void dfs(StringBuilder buffer, int k, int n) {
        if (buffer.length() == n) {
            numbers.add(Integer.parseInt(buffer.toString()));
        } else {
            int num = buffer.charAt(buffer.length() - 1) - '0';
            if (num + k < 10) {
                buffer.append(num + k);
                dfs(buffer, k, n);
                buffer.deleteCharAt(buffer.length() - 1);
            }
            if (num - k >= 0 && k != 0) {
                buffer.append(num - k);
                dfs(buffer, k, n);
                buffer.deleteCharAt(buffer.length() - 1);
            }
        }
    }
}
