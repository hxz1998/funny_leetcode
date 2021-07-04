/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No05dot02 {
    public String printBin(double num) {
        if (num >= 1 || num < 0) return "ERROR";
        StringBuilder builder = new StringBuilder();
        builder.append("0.");
        while (num > 0) {
            if (builder.length() > 32) return "ERROR";
            double r = num * 2;
            if (r > 1) {
                builder.append("1");
                num = r - 1;
            } else {
                builder.append("0");
                num = r;
            }
        }
        return builder.toString();
    }
}
