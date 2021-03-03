/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No831 {
    public String maskPII(String S) {
        int idx = S.indexOf('@');
        if (idx >= 0) {
            // 如果是一个邮件，那么久好处理了，直接选出来前面的和后面的字符就可以拼接了
            return (S.substring(0, 1) + "*****" + S.substring(idx - 1)).toLowerCase();
        } else {
            // 如果是电话，那么就稍微麻烦一点
            // 首先把字符串中不是数字的字符全部给删掉
            String digits = S.replaceAll("\\D+", "");
            // 然后取出来最后四位数字，做成本地号码
            String local = "***-***-" + digits.substring(digits.length() - 4);
            // 如果有效数字长度就是10个，那么就直接返回好了
            if (digits.length() == 10) return local;
            // 否则的话，就需要添加国际号
            StringBuilder ans = new StringBuilder("+");
            // 从前往后挨个添加*
            for (int i = 0; i < digits.length() - 10; ++i) ans.append("*");
            return ans.append("-").append(local).toString();
        }
    }
}
