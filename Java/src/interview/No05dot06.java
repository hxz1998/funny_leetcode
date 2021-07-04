/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No05dot06 {
    public int convertInteger(int A, int B) {
        A = A ^ B;
        B = 0;
        while (A != 0) {
            B += (A & 1);
            A >>= 1;
        }
        return B;
    }

    public static void main(String[] args) {
        No05dot06 no05dot06 = new No05dot06();
        System.out.println(no05dot06.convertInteger(826966453, -729934991));
    }
}
