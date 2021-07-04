/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class No08dot09 {
    public List<String> generateParenthesis(int n) {
        return new ArrayList<>(permutation(n));
    }

    private Set<String> permutation(int n) {
        HashSet<String> set = new HashSet<>();
        if (n == 0) {
            set.add("");
        } else {
            // 先构建长度小的, 再递归构建长的
            Set<String> prev = permutation(n - 1);
            for (String item : prev) {
                // 在前面的每一个左括号后面添加一个括号
                for (int i = 0; i < item.length(); ++i) {
                    if (item.charAt(i) == '(') set.add(insert(item, i));
                }
                // 在最后一个位置添加括号
                set.add(item + "()");
            }
        }
        return set;
    }

    private String insert(String str, int idx) {
        // 因为需要放到 idx 之后，所以需要 + 1
        String prefix = str.substring(0, idx + 1);
        String suffix = str.substring(idx + 1);
        return prefix + "()" + suffix;
    }
}
