/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;
import java.util.Comparator;

public class No853 {
    static class Car {
        int position;
        double time;

        Car(int position, double time) {
            this.position = position;
            this.time = time;
        }
    }

    public int carFleet(int target, int[] position, int[] speed) {
        int size = position.length;
        Car[] cars = new Car[size];
        // 对每一辆车的位置进行记录，并且计算其到达目的地需要的时间
        for (int i = 0; i < size; ++i) {
            cars[i] = new Car(position[i], (double) (target - position[i]) / speed[i]);
        }
        // 根据当前位置进行降序排序，靠近终点的排前面
        Arrays.sort(cars, (a, b) -> Integer.compare(a.position, b.position));
        // ans 用来记录多少个车队，t 用来记录处理到第几个了
        int ans = 0, t = size;
        while (--t > 0) {
            // 如果离终点近的车到终点需要的时间比离终点远的车需要的时间少，那么就增加一个车队
            if (cars[t].time < cars[t - 1].time) ans++;
                // 否则就并入当前车队
            else cars[t - 1] = cars[t];
        }
        return ans + (t == 0 ? 1 : 0);
    }

    public static void main(String[] args) {
        No853 test = new No853();
        int[] position = new int[]{10, 8, 0, 5, 3};
        int[] speed = new int[]{2, 4, 1, 1, 3};
        System.out.println(test.carFleet(12, position, speed));
    }
}
