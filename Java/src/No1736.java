/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1736 {
    public String maximumTime(String time) {
        char[] cs = time.toCharArray();
        for (int i = 0; i < time.length(); ++i) {
            if (cs[i] == '?') switch (i) {
                case 0:
                    if (cs[i + 1] == '?' || cs[i + 1] < '4') cs[i] = '2';
                    else cs[i] = '1';
                    break;
                case 1:
                    if (cs[i - 1] == '2') cs[i] = '3';
                    else cs[i] = '9';
                    break;
                case 3:
                    cs[i] = '5';
                    break;
                case 4:
                    cs[i] = '9';
                    break;
            }
        }
        return new String(cs);
    }
}
