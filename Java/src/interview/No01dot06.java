/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No01dot06 {
    public String compressString(String s) {
        // 使用StringBuilder来优化修改字符串的操作
        StringBuilder builder = new StringBuilder();
        int count = 0;  // 计数当前字符出现的次数
        for (int i = 0; i < s.length(); ++i) {
            // 首先自增 1
            count++;
            // 如果 i 已经走到字符串末尾了，或者当前字符（i）和下一个字符（i+1）不一样，
            if (i + 1 >= s.length() || s.charAt(i) != s.charAt(i + 1)) {
                // 那么就先把当前字符放到压缩字符串中
                builder.append(s.charAt(i)).append(count);
                // 然后清空计数
                count = 0;
            }
        }
        String res = builder.toString();
        // 最后看看哪一个短
        return res.length() < s.length() ? res : s;
    }
}
