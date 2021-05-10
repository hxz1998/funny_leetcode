/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1332 {
    public int removePalindromeSub(String s) {
        return s.length() == 0 ? 0 : new StringBuilder(s).reverse().toString().equals(s) ? 1 : 2;
    }
}
