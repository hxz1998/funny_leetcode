/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest51;

import java.util.*;

public class No4 {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        int[] ans = new int[queries.length];
        Arrays.sort(rooms, Comparator.comparingInt(o -> o[0]));
        int idx = 0;
        for (int[] query : queries) {
            ans[idx++] = find(rooms, query[0], query[1]);
        }
        return ans;
    }

    private int find(int[][] rooms, int id, int minSize) {
        if (id > rooms.length) {
            int right = rooms.length - 1;
            while (right >= 0) {
                if (rooms[right][1] >= minSize) return rooms[right][0];
                right--;
            }
        } else {
            int left = id - 1, right = id;
            while (left >= 0) {
                if (rooms[left][1] >= minSize) return rooms[left][0];
                else left--;
            }
            while (right < rooms.length) {
                if (rooms[right][1] >= minSize) return rooms[right][0];
                else right++;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(Integer.MAX_VALUE);
    }
}
