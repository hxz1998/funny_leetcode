/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No1078 {
    public String[] findOcurrences(String text, String first, String second) {
        // 首先按照 " " 空格去切分字符串
        String[] words = text.split(" ");
        List<String> list = new ArrayList<>();
        // 然后按照规则直接检查就可以了
        for (int i = 0; i < words.length - 2; ++i) {
            if (words[i].equals(first) && words[i + 1].equals(second))
                // 遇到符合要求的，直接添加进返回值
                list.add(words[i + 2]);
        }
        String[] ans = new String[list.size()];
        list.toArray(ans);
        return ans;
    }
}
