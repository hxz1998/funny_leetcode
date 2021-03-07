/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest231;

import java.util.List;

public class No1 {
    public boolean checkOnesSegment(String s) {
        String[] list = s.split("0");
        int count = 0;
        for (String item : list) {
            if (!item.equals("")) count++;
        }
        return count <= 1;
    }

    public static void main(String[] args) {
        No1 no1 = new No1();
        System.out.println(no1.checkOnesSegment("1001"));
        System.out.println(no1.checkOnesSegment("110"));
        System.out.println(no1.checkOnesSegment("1100111"));
        System.out.println(no1.checkOnesSegment("1"));
        System.out.println(no1.checkOnesSegment("10"));
    }
}
