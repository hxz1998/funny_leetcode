/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No13 {
    public int romanToInt(String s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            char symbol = s.charAt(i);
            if (symbol == 'C' && n - i > 1 && s.charAt(i + 1) == 'M') {
                ans += 900;
                i++;
            } else if (symbol == 'C' && n - i > 1 && s.charAt(i + 1) == 'D') {
                ans += 400;
                i++;
            } else if (symbol == 'X' && n - i > 1 && s.charAt(i + 1) == 'L') {
                ans += 40;
                i++;
            } else if (symbol == 'X' && n - i > 1 && s.charAt(i + 1) == 'C') {
                ans += 90;
                i++;
            } else if (symbol == 'I' && n - i > 1 && s.charAt(i + 1) == 'V') {
                ans += 4;
                ++i;
            } else if (symbol == 'I' && n - i > 1 && s.charAt(i + 1) == 'X') {
                ans += 9;
                ++i;
            } else if (symbol == 'M') ans += 1000;
            else if (symbol == 'D') ans += 500;
            else if (symbol == 'C') ans += 100;
            else if (symbol == 'L') ans += 50;
            else if (symbol == 'X') ans += 10;
            else if (symbol == 'V') ans += 5;
            else if (symbol == 'I') ans += 1;
        }
        return ans;
    }
}
