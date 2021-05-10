/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.List;

public class No165 {
    public int compareVersion(String version1, String version2) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        String[] ss1 = version1.split("\\.");
        String[] ss2 = version2.split("\\.");
        for (String item : ss1) list1.add(Integer.parseInt(item));
        for (String item : ss2) list2.add(Integer.parseInt(item));

        int n = Math.min(list1.size(), list2.size());
        for (int i = 0; i < n; ++i) {
            int ver1 = list1.get(i);
            int ver2 = list2.get(i);
            if (ver1 < ver2) return -1;
            else if (ver1 > ver2) return 1;
        }
        if (list1.size() > list2.size()) {
            for (int i = n; i < list1.size(); ++i) if (list1.get(i) > 0) return 1;
        } else if (list1.size() < list2.size()) {
            for (int i = n; i < list2.size(); ++i) if (list2.get(i) > 0) return -1;
        }
        return 0;
    }

    public static void main(String[] args) {
        No165 no165 = new No165();

        System.out.println(no165.compareVersion("0.1", "1.1"));
    }
}
