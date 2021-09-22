/*
 * Copyright (c) 8/21/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No443 {
    public int compress(char[] chars) {
        int idx = 0;
        for (int i = 0; i < chars.length; ) {
            char c = chars[i];
            int cnt = 0;
            while (i < chars.length && chars[i] == c) {
                i++;
                cnt++;
            }
            if (cnt == 1) chars[idx++] = c;
            else {
                chars[idx++] = c;
                StringBuilder builder = new StringBuilder();
                while (cnt > 0) {
                    builder.append(cnt % 10);
                    cnt /= 10;
                }
                for (int j = builder.length() - 1; j >= 0; --j) chars[idx++] = builder.charAt(j);
            }
        }
        return idx;
    }

    public static void main(String[] args) {
        No443 no443 = new No443();
        char[] chars = {'a'};
        int len = no443.compress(chars);
        System.out.println(len);
        for (int i = 0; i < len; ++i) System.out.printf("%c ", chars[i]);
    }
}
