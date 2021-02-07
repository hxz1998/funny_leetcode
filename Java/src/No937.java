import java.util.Arrays;

/**
 * Created by Xiaozhong on 2021/2/1.
 * Copyright (c) 2021/2/1 Xiaozhong. All rights reserved.
 */

public class No937 {
    public String[] reorderLogFiles(String[] logs) {
        // 使用正则表达式来完成
        Arrays.sort(logs, (log1, log2) -> {
            // 首先切分两个序列，把它们按照空格去切分成两个
            String[] str1 = log1.split(" ", 2);
            String[] str2 = log2.split(" ", 2);
            // 检查除去第一个标识符之外，是否是数字日志
            boolean isDigit1 = Character.isDigit(str1[1].charAt(0));
            boolean isDigit2 = Character.isDigit(str2[1].charAt(0));
            // 如果都不是数字日志，那么就触发检查过程
            if (!isDigit1 && !isDigit2) {
                // 比较两个字母日志
                int cmp = str1[1].compareTo(str2[1]);
                // 如果字母日志不相同，那么就直接返回比较结果
                if (cmp != 0) return cmp;
                // 否则就使用它们的标识符来排序
                return str1[0].compareTo(str2[0]);
            }
            // 当有一个是数字日志时，就把数字日志排在后面
            return isDigit1 ? (isDigit2 ? 0 : 1) : -1;
        });
        return logs;
    }
}
