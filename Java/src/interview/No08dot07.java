/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.Arrays;

public class No08dot07 {
    public String[] permutation(String s) {
        // 使用递归函数进行遍历处理
        return helper(s).toArray(new String[0]);
    }

    private ArrayList<String> helper(String s) {
        // 如果原字符串就是空指针, 此时直接返回 null 就好了
        if (s == null) return null;
        ArrayList<String> permutations = new ArrayList<>();
        // 如果原字符串是空的, 那么就返回一个空结果
        if (s.length() == 0) {
            permutations.add("");
            return permutations;
        }
        // 首先取出来第一个字符,方便后面进行操作
        char c = s.charAt(0);
        // 取出来剩余的字符串
        String remainder = s.substring(1);
        // 先将剩余的字符串进行全排列
        var words = helper(remainder);
        for (String word : words) {
            // 然后对剩余字符串构成的每一个排列, 遍历可插入位置, 放入字符 c
            // 这里一定要使用 小于等于， 因为需要在最后一个位置以及第一个位置上插入
            for (int i = 0; i <= word.length(); ++i) {
                String ret = insertCharacter(i, c, word);
                // 再把最后的结果放到返回值中
                permutations.add(ret);
            }
        }
        // 返回就好了
        return permutations;
    }

    private String insertCharacter(int idx, char c, String s) {
        String prefix = s.substring(0, idx);
        String suffix = s.substring(idx);
        return prefix + c + suffix;
    }

    public static void main(String[] args) {
        No08dot07 no08dot07 = new No08dot07();
        System.out.println(Arrays.toString(no08dot07.permutation("qwe")));
    }
}
