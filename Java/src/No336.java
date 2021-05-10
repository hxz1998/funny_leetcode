/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class No336 {
    static class Node {
        int id = -1;
        int[] children = new int[26];
    }

    List<Node> tree = new ArrayList<>();

    public List<List<Integer>> palindromePairs(String[] words) {
        tree.add(new Node());
        for (int i = 0; i < words.length; ++i) insert(words[i], i);

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < words.length; ++i) {
            int m = words[i].length();
            for (int j = 0; j <= m; ++j) {
                if (isPalindrome(words[i], j, m - 1)) {
                    int leftId = findWord(words[i], 0, j - 1);
                    if (leftId != -1 && leftId != i) ans.add(Arrays.asList(i, leftId));
                }
                if (j != 0 && isPalindrome(words[i], 0, j - 1)) {
                    int rightId = findWord(words[i], j, m - 1);
                    if (rightId != -1 && rightId != i) ans.add(Arrays.asList(rightId, i));
                }
            }
        }
        return ans;
    }

    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left++) != s.charAt(right--)) return false;
        }
        return true;
    }

    private void insert(String s, int id) {
        int len = s.length(), prev = 0;
        for (int i = 0; i < len; ++i) {
            int x = s.charAt(i) - 'a';
            if (tree.get(prev).children[x] == 0) {
                tree.add(new Node());
                tree.get(prev).children[x] = tree.size() - 1;
            }
            prev = tree.get(prev).children[x];
        }
        tree.get(prev).id = id;
    }

    private int findWord(String s, int left, int right) {
        int prev = 0;
        for (int i = right; i >= left; --i) {
            int x = s.charAt(i) - 'a';
            if (tree.get(prev).children[x] == 0) return -1;
            prev = tree.get(prev).children[x];
        }
        return tree.get(prev).id;
    }

    public static void main(String[] args) {
        No336 no336 = new No336();
    }
}
