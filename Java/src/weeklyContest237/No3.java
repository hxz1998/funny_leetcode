/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest237;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class No3 {
    // 对象化每一个任务，id 就是下标，time 就是开始时间和持续时间
    static class Task {
        int id;
        int[] time;

        Task(int id, int[] time) {
            this.id = id;
            this.time = time;
        }
    }

    public int[] getOrder(int[][] tasks) {
        int n = tasks.length;
        Task[] ts = new Task[n];
        // new 出来每一个任务数据结构，方便排序
        for (int i = 0; i < n; ++i) ts[i] = new Task(i, tasks[i]);
        // 按照开始时间递增排好序
        Arrays.sort(ts, Comparator.comparingInt(o -> o.time[0]));
        // 优先级队列，比较器需要【保证首先按照消耗时间从小到大排列，然后保证同样消耗时间的 id 小的排前面】
        PriorityQueue<Task> priorityQueue = new PriorityQueue<>((o1, o2) ->
                o1.time[1] == o2.time[1] ? o1.id - o2.id : o1.time[1] - o2.time[1]
        );
        // 直接从第一个任务开始的时间开始累加计时
        long T = ts[0].time[0];
        // ans 表示返回值， idx 表示返回值中的下标
        int[] ans = new int[n];
        int idx = 0;
        // 把所有开始时间 time[0] 不超过 T 的任务加到优先级队列里面
        int iter = 0;   // iter 表示将要添加到优先级队列中第几个了
        for (; iter < n; ++iter) {
            // 把所有不超过当前时间 T 的元素都放到优先级队列里面去
            if (ts[iter].time[0] <= T) priorityQueue.offer(ts[iter]);
                // 如果 iter 指向的任务开始时间已经超过了 T，那么后面的都超过，就跳出来
            else break;
        }

        while (!priorityQueue.isEmpty()) {
            Task task = priorityQueue.poll();
            // 处理完这个任务，时间上要累加，同时往返回值中记录下标
            T += task.time[1];
            ans[idx++] = task.id;
            // 增加空转时间对齐，因为可能出现 [1, 2], [100, 5] 这样的数据，这样前后不接
            if (iter < n && priorityQueue.isEmpty() && T < ts[iter].time[0]) T = ts[iter].time[0];
            for (; iter < n; ++iter) {
                // 把所有不超过当前时间 T 的元素都放到优先级队列里面去
                if (ts[iter].time[0] <= T) priorityQueue.offer(ts[iter]);
                    // 如果 iter 指向的任务开始时间已经超过了 T，那么后面的都超过，就跳出来
                else break;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
        No3 no3 = new No3();

        System.out.println(Arrays.toString(no3.getOrder(tasks)));

        tasks = new int[][]{{19, 13}, {16, 9}, {21, 10}, {32, 25}, {37, 4}, {49, 24}, {2, 15}, {38, 41}, {37, 34}, {33, 6}, {45, 4}, {18, 18}, {46, 39}, {12, 24}};
        System.out.println(Arrays.toString(no3.getOrder(tasks)).equals("[6, 1, 2, 9, 4, 10, 0, 11, 5, 13, 3, 8, 12, 7]"));

        tasks = new int[][]{{1, 2}, {5, 2}};
        System.out.println(Arrays.toString(no3.getOrder(tasks)));
    }
}
