/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No761 {

    public String makeLargestSpecial(String s) {
        int cnt = 0;
        List<String> list = new ArrayList<>();
        int pos = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '1') cnt++;
            else cnt--;
            if (cnt == 0) {
                list.add("1" + makeLargestSpecial(s.substring(pos + 1, i)) + "0");
                pos = i + 1;
            }
        }
        StringBuilder ret = new StringBuilder();
        list.sort(Comparator.reverseOrder());
        for (String item : list) ret.append(item);
        return ret.toString();
    }

    public static void main(String[] args) {
        No761 no761 = new No761();
        System.out.println(no761.makeLargestSpecial("11011000"));
        System.out.println(no761.makeLargestSpecial("11100010"));
    }

}
