/*
 * Copyright (c) 8/12/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1647 {
    public int minDeletions(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) cnt[s.charAt(i) - 'a']++;
        Arrays.sort(cnt);
        int ans = 0;
        for (int i = 24; i >= 0; --i) {
            if (cnt[i] == 0) continue;
            if (cnt[i] >= cnt[i + 1]) {
                ans += cnt[i + 1] == 0 ? cnt[i] : cnt[i] - cnt[i + 1] + 1;
                cnt[i] = cnt[i + 1] == 0 ? 0 : cnt[i + 1] - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        No1647 no1647 = new No1647();
        System.out.println(no1647.minDeletions("beaddedbacdcd"));
    }
}
