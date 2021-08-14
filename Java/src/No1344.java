/*
 * Copyright (c) 8/14/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1344 {
    public double angleClock(int hour, int minutes) {
        // 如果时针为 12 时，那么应该是 0° 基本度数，因此需要模 360
        double hourAngle = hour * 30 % 360;
        // 分针也一样
        double minuteAngle = minutes * 6 % 360;
        // 时针加上分针带来的影响
        hourAngle += minutes * 0.5;
        // 找到两个针的夹角
        double angle = Math.abs(hourAngle - minuteAngle);
        // 需要返回最小的那个度数
        return Math.min(angle, 360 - angle);
    }

    public static void main(String[] args) {
        No1344 no1344 = new No1344();
        System.out.println(no1344.angleClock(12, 0));
        System.out.println(no1344.angleClock(4, 50));
        System.out.println(no1344.angleClock(3, 15));
    }
}
