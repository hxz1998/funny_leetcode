/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest251;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class No3 {
    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        Arrays.sort(students, (o1, o2) -> {
            for (int i = 0; i < o1.length; ++i) {
                if (o1[i] != o2[i]) return o1[i] - o2[i];
            }
            return 0;
        });
        Arrays.sort(mentors, (o1, o2) -> {
            for (int i = 0; i < o1.length; ++i) {
                if (o1[i] != o2[i]) return o1[i] - o2[i];
            }
            return 0;
        });
        int ans = 0;
        Set<Integer> studentSet = new HashSet<>(), mentorSet = new HashSet<>();
        for (int i = 0; i < students.length; ++i) {
            int max = 0;
            int j = 0;
            for (; j < mentors.length; ++j) {
                int tmp = 0;
                for (int k = 0; k < students[i].length; ++k) {
                    if (mentors[j][k] == students[i][k]) tmp++;
                }
                if (max < tmp) {
                    mentorSet.add(j);
                }
            }
            ans += max;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] students = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
        int[][] mentors = {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}};
        No3 no3 = new No3();
        System.out.println(no3.maxCompatibilitySum(students, mentors));
    }
}
