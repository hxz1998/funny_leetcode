/*
 * Copyright (c) 10/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest263;

public class No1 {
    public boolean areNumbersAscending(String s) {
        String[] tokens = s.split(" ");
        int prev = -1;
        for (String item : tokens) {
            try {
                int value = Integer.parseInt(item);
                if (value > prev) prev = value;
                else return false;
            } catch (Exception e) {
                // DO NOTHING
            }
        }
        return true;
    }

    public static void main(String[] args) {

    }
}
