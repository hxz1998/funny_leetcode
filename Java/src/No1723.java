/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;

public class No1723 {
    public int minimumTimeRequired(int[] jobs, int k) {
        Arrays.sort(jobs);
        int left = jobs[jobs.length - 1], right = Arrays.stream(jobs).sum();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(jobs, k, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    private boolean check(int[] jobs, int k, int limit) {
        int[] workloads = new int[k];
        return backtrace(jobs, workloads, jobs.length - 1, limit);
    }

    private boolean backtrace(int[] jobs, int[] workloads, int idx, int limit) {
        if (idx < 0) return true;
        int job = jobs[idx];
        for (int i = 0; i < workloads.length; ++i) {
            if (workloads[i] + job <= limit) {
                workloads[i] += job;
                if (backtrace(jobs, workloads, idx - 1, limit)) return true;
                workloads[i] -= job;
            }
            // 等于 0 是因为工作不管怎样分配，都会超过 limit 限制，所以直接返回 false 就好了
            // workloads[i] + job == limit，而且前面么有返回 true，那么说明后面不管怎样分配，都不会有 true 了
            if (workloads[i] == 0 || workloads[i] + job == limit) break;
        }
        return false;
    }
}
