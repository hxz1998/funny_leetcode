/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package offer;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class No38 {
    private List<String> rec;
    private boolean[] visited;

    public String[] permutation(String s) {
        int n = s.length();
        rec = new ArrayList<>();
        visited = new boolean[n];
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        backtrack(arr, n, 0, new StringBuilder());
        return rec.toArray(new String[0]);
    }

    private void backtrack(char[] arr, int n, int idx, StringBuilder builder) {
        if (idx == n) {
            rec.add(builder.toString());
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i] || (i > 0 && !visited[i - 1] && arr[i] == arr[i - 1])) continue;
            visited[i] = true;
            builder.append(arr[i]);
            backtrack(arr, n, idx + 1, builder);
            builder.deleteCharAt(builder.length() - 1);
            visited[i] = false;
        }
    }
}
