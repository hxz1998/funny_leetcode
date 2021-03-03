/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No833 {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int size = S.length();
        // match 数组用来记录每一个 index 是否匹配
        // 如果匹配那么就记录下来应该用 target 中的哪一个字符串进行替换
        int[] match = new int[size];
        Arrays.fill(match, -1);

        // 检查是否匹配
        for (int i = 0; i < indexes.length; ++i) {
            int start = indexes[i];
            if (S.substring(start, start + sources[i].length()).equals(sources[i])) {
                match[start] = i;
            }
        }

        StringBuilder stringBuilder = new StringBuilder();
        // idx 是一个用来遍历原字符串的游标
        int idx = 0;
        while (idx < size) {
            if (match[idx] >= 0) {
                // 如果匹配到了，那么就直接把字符串进行追加，然后把游标增加被替换字符串的长度
                stringBuilder.append(targets[match[idx]]);
                idx += sources[match[idx]].length();
            } else {
                // 否则就直接添加原字符串中的那个字符
                stringBuilder.append(S.charAt(idx++));
            }
        }
        return stringBuilder.toString();
    }
}
