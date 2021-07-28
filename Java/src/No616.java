/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No616 {

    public String addBoldTag(String s, String[] words) {
        int n = s.length();
        boolean[] mask = new boolean[n];
        for (int i = 0; i < n; ++i) {
            for (String word : words) {
                int len = word.length();
                if (i + len <= n && s.substring(i, i + len).equals(word)) {
                    for (int idx = i; idx < i + word.length(); ++idx) mask[idx] = true;
                }
            }
        }
        StringBuilder builder = new StringBuilder();
        for (int idx = 0; idx < n; ++idx) {
            if (mask[idx] && (idx == 0 || !mask[idx - 1])) builder.append("<b>");
            builder.append(s.charAt(idx));
            if (mask[idx] && (idx == n - 1 || !mask[idx + 1])) builder.append("</b>");
        }
        return builder.toString();
    }

    public static void main(String[] args) {
        String string = "abcxyz123";
        String[] dict = {"abc", "123"};
        No616 no616 = new No616();
        System.out.println(no616.addBoldTag(string, dict));
        System.out.println(string.substring(6, 9));
    }
}
