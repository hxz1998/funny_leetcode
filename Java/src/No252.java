/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No252 {
    public boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals, ((o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0]));
        for (int idx = 0; idx < intervals.length - 1; ++idx) {
            if (intervals[idx][1] > intervals[idx + 1][0]) return false;
        }
        return true;
    }
}
