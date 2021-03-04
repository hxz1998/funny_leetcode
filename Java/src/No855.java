/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.TreeSet;

public class No855 {
}

class ExamRoom {
    int size;
    TreeSet<Integer> students;

    public ExamRoom(int N) {
        this.size = N;
        students = new TreeSet<>();
    }

    public int seat() {
        // 首先默认学生是在第一个位置的
        int student = 0;
        // 然后挨个检查后面的学生位置
        if (students.size() > 0) {
            // 两两比较，看两者之间的空位长度
            int dist = students.first();
            int prev = -1;
            for (int s : students) {
                if (prev != -1) {
                    // 找到最大的，两个学生之间的位置
                    int d = (s - prev) / 2;
                    if (d > dist) {
                        dist = d;
                        student = prev + d;
                    }
                }
                prev = s;
            }
            // 也要检查是否能放在最后一个位置
            if (size - 1 - students.last() > dist) student = size - 1;
        }
        // 放下来该生
        students.add(student);
        return student;
    }

    public void leave(int p) {
        students.remove(p);
    }
}
