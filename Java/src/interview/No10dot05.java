/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No10dot05 {
    private int search(String[] words, String s, int first, int last) {
        if (first > last) return -1;
        int mid = first + (last - first) / 2;
        if (words[mid].isEmpty()) {
            int left = mid - 1;
            int right = mid + 1;
            while (true) {
                if (left < first && right > last) return -1;
                else if (left >= first && !words[left].isEmpty()) {
                    mid = left;
                    break;
                } else if (right <= last && !words[right].isEmpty()) {
                    mid = right;
                    break;
                }
                right++;
                left--;
            }
        }
        if (s.equals(words[mid])) return mid;
        else if (words[mid].compareTo(s) < 0) return search(words, s, mid + 1, last);
        else return search(words, s, first, mid - 1);
    }

    public int findString(String[] words, String s) {
        if (words.length == 1) return words[0].equals(s) ? 0 : -1;
        int left = 0, right = words.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int temp = mid;
            while (mid < right && words[mid].isEmpty()) mid++;
            if (right == mid) {
                right = temp;
                continue;
            }
            if (words[mid].equals(s)) return mid;
            else if (words[mid].compareTo(s) < 0) left = mid + 1;
            else right = mid;
        }
        return words[left].equals(s) ? left : -1;
    }

    public static void main(String[] args) {
        String[] words = {"CfGvij", "Jhj", "UZDrCzHCXeeUmZAfgIvH", "zFgLCkLLzDBd"};
        No10dot05 no10dot05 = new No10dot05();
        System.out.println(no10dot05.findString(words, "zFgLCkLLzDBd"));
        words = new String[]{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
        System.out.println(no10dot05.findString(words, "ball"));
    }
}
