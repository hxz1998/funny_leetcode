/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class Page46 {
    private static void permutation(String str) {
        permutation(str, "");
    }

    private static void permutation(String str, String prefix) {
        if (str.length() == 0) System.out.println(prefix);
        else {
            for (int i = 0; i < str.length(); ++i) {
                String remain = str.substring(0, i) + str.substring(i + 1);
                permutation(remain, prefix + str.charAt(i));
            }
        }
    }

    public static void main(String[] args) {
        Page46.permutation("ABC");
    }
}
