/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No91 {
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') return 0;
        char[] charArray = s.toCharArray();
        int prev = 1, curr = 1;
        for (int i = 1; i < s.length(); ++i) {
            int tmp = curr;
            if (charArray[i] == '0') {
                if (charArray[i - 1] == '1' || charArray[i - 1] == '2') curr = prev;
                else return 0;
            } else if (charArray[i - 1] == '1' || (charArray[i - 1] == '2' && charArray[i] <= '6')) {
                curr = curr + prev;
            }
            prev = tmp;
        }
        return curr;
    }

    public static void main(String[] args) {
        No91 no91 = new No91();
        System.out.println(no91.numDecodings("226"));
        System.out.println(no91.numDecodings("27"));
    }
}
