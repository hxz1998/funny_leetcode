/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;

public class No1507 {
    private String[] months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    public String reformatDate(String date) {
        Map<String, Integer> mapper = new HashMap<>();
        for (int i = 0; i < months.length; ++i) mapper.put(months[i], i + 1);

        String[] items = date.split(" ");
        String day = items[0].substring(0, items[0].length() - 2), month = items[1], year = items[2];
        return String.format("%d-%02d-%02d", Integer.parseInt(year), mapper.get(month), Integer.parseInt(day));
    }
}
