/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package lcvscode;

public class No1 {
    public int leastMinutes(int n) {
        int speed = 1;
        int times = 0;
        while (speed * 2 <= n){
            speed = speed * 2;
            times++;
        }
        return (int) (times + Math.ceil(1.0 * n / speed));
    }

    public static void main(String[] args) {
        No1 no1 = new No1();
        System.out.println(no1.leastMinutes(3));
    }
}
