/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest49;

public class No1 {
    public boolean squareIsWhite(String coordinates) {
        int x = coordinates.charAt(0) - 'a' + 1;
        int y = coordinates.charAt(1) - '0';
        return (x & 1) == 1 ? (y & 1) == 1 ? false : true : (y & 1) == 0 ? false : true;
    }

    public static void main(String[] args) {
        System.out.println();
    }
}
