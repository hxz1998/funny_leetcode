/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.regex.Pattern;

public class No65 {
    public boolean isNumber(String s) {
        String number = "([+-]?(\\d+(\\.\\d*)?|(\\.\\d+)))";
        Pattern base = Pattern.compile(number + "([eE][+-]?\\d+)?");
        return base.matcher(s).matches();
    }

    public static void main(String[] args) {
        No65 no65 = new No65();
        Pattern pattern = Pattern.compile("[+-]?(\\d+(\\.\\d*)?|\\.\\d+)([eE][+-]?\\d+)?$");
        System.out.println(no65.isNumber("2e0"));
        System.out.println(no65.isNumber(".12"));
        System.out.println(no65.isNumber("20"));
        System.out.println(pattern.matcher("2e0").matches());
        System.out.println(no65.isNumber("+.8"));
        System.out.println(no65.isNumber(".20"));
        System.out.println(no65.isNumber(".0e7"));
        System.out.println(no65.isNumber(".0"));
    }
}
