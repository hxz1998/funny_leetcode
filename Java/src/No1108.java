/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1108 {
    public String defangIPaddr(String address) {
        StringBuilder sb = new StringBuilder();
        for (char c : address.toCharArray()) {
            if (c == '.') sb.append("[" + c + "]");
            else sb.append(c);
        }
        return sb.toString();
    }
}
