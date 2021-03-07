/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.*;

public class No131 {
    private boolean check(String s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s.charAt(left++) != s.charAt(right--)) return false;
        }
        return true;
    }

    private void backtrace(String s, List<List<String>> ans, Deque<String> path, int start) {
        if (start >= s.length()) {
            Iterator<String> iter = path.iterator();
            List<String> list = new ArrayList<>();
            while (iter.hasNext()) {
                list.add(iter.next());
            }
            ans.add(list);
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            String subString = s.substring(start, i + 1);
            if (!check(subString)) continue;
            path.addLast(subString);
            backtrace(s, ans, path, i + 1);
            path.pollLast();
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        Deque<String> path = new LinkedList<>();
        backtrace(s, ans, path, 0);
        return ans;
    }

    public static void main(String[] args) {
        No131 no131 = new No131();
        System.out.println(no131.partition("aab"));
        System.out.println("abcdefg".substring(0, 3));
    }
}
