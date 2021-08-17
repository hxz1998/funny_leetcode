/*
 * Copyright (c) 8/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No551 {
    public boolean checkRecord(String s) {
        if (s.contains("LLL")) return false;
        int cnt = 0;
        for (char c : s.toCharArray()) if (c == 'A') cnt++;
        return cnt < 2;
    }
}
