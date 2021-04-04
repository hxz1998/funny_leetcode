/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No93 {
    private List<String> ans;
    private int[] ip;

    public List<String> restoreIpAddresses(String s) {
        ans = new ArrayList<>();
        ip = new int[4];
        return ans;
    }

    private void dfs(String s, int start, int segId) {
        if (segId == 4) {
            if (start == s.length()) {
                StringBuilder builder = new StringBuilder();
                for (int i = 0; i < 4; ++i) {
                    builder.append(ip[i]);
                    if (i != 3) builder.append(".");
                }
                ans.add(builder.toString());
            }
            return;
        }
        if (start == s.length()) return;
        if (s.charAt(start) == '0') {
            ip[segId] = 0;
            dfs(s, start + 1, segId + 1);
        }

        int addr = 0;
        for (int i = start; i < s.length(); ++i) {
            addr = addr * 10 + s.charAt(i) - '0';
            if (addr > 0 && addr <= 255) {
                ip[segId] = addr;
                dfs(s, i + 1, segId + 1);
            } else break;
        }
    }
}
