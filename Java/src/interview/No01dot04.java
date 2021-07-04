/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No01dot04 {
    public boolean canPermutePalindrome(String s) {
        boolean[] vector = createVector(s);
        boolean founded = false;
        for (boolean count : vector) {
            if (count) {
                if (founded) return false;
                founded = true;
            }
        }
        return true;
    }

    private boolean[] createVector(String s) {
        boolean[] vector = new boolean[256];
        for (char c : s.toCharArray()) {
            int idx = c - '!';
            if (idx < 0) continue;
            vector[idx] = !vector[idx];
        }
        return vector;
    }

    public static void main(String[] args) {
        No01dot04 no01dot04 = new No01dot04();
        System.out.println(Character.getNumericValue('a'));
        System.out.println(Character.getNumericValue('z'));
        System.out.println(Character.getNumericValue('A'));
        System.out.println(Character.getNumericValue('Z'));
        System.out.println(no01dot04.canPermutePalindrome("AaBb//a"));
    }
}
